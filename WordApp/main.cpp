#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <optional>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

namespace wordapp {

static int64_t now_epoch_seconds() {
  using namespace std::chrono;
  return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
}

static string format_time(int64_t epoch_seconds) {
  if (epoch_seconds <= 0) return "N/A";
  std::time_t t = static_cast<std::time_t>(epoch_seconds);
  std::tm tm{};
#if defined(_WIN32)
  localtime_s(&tm, &t);
#else
  localtime_r(&t, &tm);
#endif
  std::ostringstream oss;
  oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}

static string trim(string s) {
  auto is_space = [](unsigned char c) { return std::isspace(c) != 0; };
  while (!s.empty() && is_space(static_cast<unsigned char>(s.front()))) s.erase(s.begin());
  while (!s.empty() && is_space(static_cast<unsigned char>(s.back()))) s.pop_back();
  return s;
}

static string to_lower_ascii(string s) {
  for (char &c : s) {
    if ('A' <= c && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
  }
  return s;
}

static string escape_field(string_view s) {
  // Tab-separated single line record. Escape: '\' => "\\", '\t' => "\t", '\n' => "\n", '\r' => "\r"
  string out;
  out.reserve(s.size());
  for (char c : s) {
    switch (c) {
      case '\\': out += "\\\\"; break;
      case '\t': out += "\\t"; break;
      case '\n': out += "\\n"; break;
      case '\r': out += "\\r"; break;
      default: out.push_back(c); break;
    }
  }
  return out;
}

static bool unescape_field(const string &in, string &out) {
  out.clear();
  out.reserve(in.size());
  for (size_t i = 0; i < in.size(); ++i) {
    char c = in[i];
    if (c != '\\') {
      out.push_back(c);
      continue;
    }
    if (i + 1 >= in.size()) return false;
    char n = in[++i];
    switch (n) {
      case '\\': out.push_back('\\'); break;
      case 't': out.push_back('\t'); break;
      case 'n': out.push_back('\n'); break;
      case 'r': out.push_back('\r'); break;
      default: return false;
    }
  }
  return true;
}

struct WordEntry {
  string word;          // original
  string word_key;      // normalized for key lookup
  string meaning_cn;

  int64_t added_time = 0;
  int64_t last_review_time = 0;

  bool is_key = false;      // 重点背诵
  bool retired = false;     // 'k': 不再背诵（仍可查询）

  int review_count = 0;     // 背诵次数（y/n/t/k 都算一次交互）
  int ebb_stage = 0;        // 0..N, index into intervals; stage advances on 'y'
  int64_t next_due_time = 0;
};

static const vector<int64_t> &ebb_intervals_seconds() {
  // Ebbinghaus-like schedule (approx):
  // immediate, 20min, 1h, 9h, 1d, 2d, 6d, 31d
  static const vector<int64_t> k = {
      0,
      20 * 60,
      60 * 60,
      9 * 60 * 60,
      24 * 60 * 60,
      2 * 24 * 60 * 60,
      6 * 24 * 60 * 60,
      31 * 24 * 60 * 60,
  };
  return k;
}

class WordBook {
 public:
  explicit WordBook(string db_path) : db_path_(std::move(db_path)) {}

  bool load() {
    entries_.clear();
    index_.clear();

    ifstream fin(db_path_, ios::in);
    if (!fin.is_open()) return true;  // No file yet is OK.

    string line;
    int line_no = 0;
    while (std::getline(fin, line)) {
      ++line_no;
      if (line.empty()) continue;
      if (line.rfind("#", 0) == 0) continue;

      vector<string> cols;
      split_tsv(line, cols);
      if (cols.size() < 10) continue;

      WordEntry e;
      string tmp;
      if (!unescape_field(cols[0], e.word)) continue;
      e.word_key = to_lower_ascii(trim(e.word));
      if (!unescape_field(cols[1], e.meaning_cn)) continue;
      e.added_time = to_i64(cols[2]).value_or(0);
      e.last_review_time = to_i64(cols[3]).value_or(0);
      e.is_key = to_i64(cols[4]).value_or(0) != 0;
      e.retired = to_i64(cols[5]).value_or(0) != 0;
      e.review_count = static_cast<int>(to_i64(cols[6]).value_or(0));
      e.ebb_stage = static_cast<int>(to_i64(cols[7]).value_or(0));
      e.next_due_time = to_i64(cols[8]).value_or(0);
      // cols[9] reserved for future versioning / extra data

      // Repair invariants
      if (e.added_time <= 0) e.added_time = now_epoch_seconds();
      if (e.last_review_time <= 0) e.last_review_time = e.added_time;
      if (e.ebb_stage < 0) e.ebb_stage = 0;
      if (e.ebb_stage >= static_cast<int>(ebb_intervals_seconds().size()))
        e.ebb_stage = static_cast<int>(ebb_intervals_seconds().size()) - 1;
      if (e.next_due_time <= 0) e.next_due_time = e.last_review_time + ebb_intervals_seconds()[e.ebb_stage];

      upsert_loaded(std::move(e));
    }
    return true;
  }

  bool save() const {
    ofstream fout(db_path_, ios::out | ios::trunc);
    if (!fout.is_open()) return false;
    fout << "# wordapp-db v1\n";
    fout << "# word\\tmeaning\\tadded\\tlast_review\\tis_key\\tretired\\treview_count\\tebb_stage\\tnext_due\\treserved\n";
    for (const auto &e : entries_) {
      fout << escape_field(e.word) << '\t'
           << escape_field(e.meaning_cn) << '\t'
           << e.added_time << '\t'
           << e.last_review_time << '\t'
           << (e.is_key ? 1 : 0) << '\t'
           << (e.retired ? 1 : 0) << '\t'
           << e.review_count << '\t'
           << e.ebb_stage << '\t'
           << e.next_due_time << '\t'
           << 0 << "\n";
    }
    return true;
  }

  WordEntry *get_by_word(string_view word_input) {
    string key = to_lower_ascii(trim(string(word_input)));
    auto it = index_.find(key);
    if (it == index_.end()) return nullptr;
    return &entries_[it->second];
  }

  const WordEntry *get_by_word(string_view word_input) const {
    string key = to_lower_ascii(trim(string(word_input)));
    auto it = index_.find(key);
    if (it == index_.end()) return nullptr;
    return &entries_[it->second];
  }

  WordEntry &add_or_replace(string word, string meaning_cn) {
    word = trim(word);
    string key = to_lower_ascii(word);
    meaning_cn = trim(meaning_cn);
    int64_t now = now_epoch_seconds();

    if (auto it = index_.find(key); it != index_.end()) {
      WordEntry &e = entries_[it->second];
      e.word = word;  // keep latest casing
      e.meaning_cn = meaning_cn;
      if (e.last_review_time <= 0) e.last_review_time = now;
      if (e.added_time <= 0) e.added_time = now;
      return e;
    }

    WordEntry e;
    e.word = word;
    e.word_key = key;
    e.meaning_cn = meaning_cn;
    e.added_time = now;
    e.last_review_time = now;  // per requirement: if never reviewed, set to add time
    e.is_key = false;
    e.retired = false;
    e.review_count = 0;
    e.ebb_stage = 0;
    e.next_due_time = now + ebb_intervals_seconds()[0];
    entries_.push_back(std::move(e));
    index_[key] = static_cast<int>(entries_.size() - 1);
    return entries_.back();
  }

  vector<const WordEntry *> find_by_chinese_substring(string_view needle) const {
    string n = trim(string(needle));
    vector<const WordEntry *> out;
    if (n.empty()) return out;
    for (const auto &e : entries_) {
      if (e.meaning_cn.find(n) != string::npos) out.push_back(&e);
    }
    sort(out.begin(), out.end(), [](const WordEntry *a, const WordEntry *b) {
      return a->word_key < b->word_key;
    });
    return out;
  }

  vector<WordEntry *> all_mutable() {
    vector<WordEntry *> out;
    out.reserve(entries_.size());
    for (auto &e : entries_) out.push_back(&e);
    return out;
  }

  vector<const WordEntry *> all() const {
    vector<const WordEntry *> out;
    out.reserve(entries_.size());
    for (const auto &e : entries_) out.push_back(&e);
    return out;
  }

  size_t size() const { return entries_.size(); }

 private:
  static void split_tsv(const string &line, vector<string> &cols) {
    cols.clear();
    string cur;
    for (char c : line) {
      if (c == '\t') {
        cols.push_back(cur);
        cur.clear();
      } else {
        cur.push_back(c);
      }
    }
    cols.push_back(cur);
  }

  static optional<int64_t> to_i64(const string &s) {
    try {
      size_t idx = 0;
      long long v = std::stoll(s, &idx, 10);
      if (idx != s.size()) return std::nullopt;
      return static_cast<int64_t>(v);
    } catch (...) {
      return std::nullopt;
    }
  }

  void upsert_loaded(WordEntry e) {
    auto it = index_.find(e.word_key);
    if (it == index_.end()) {
      index_[e.word_key] = static_cast<int>(entries_.size());
      entries_.push_back(std::move(e));
      return;
    }
    // If duplicated in file, keep the latest (overwrite).
    entries_[it->second] = std::move(e);
  }

  string db_path_;
  vector<WordEntry> entries_;
  unordered_map<string, int> index_;
};

struct SessionState {
  // When user marks a word as key during dictation, it should not appear again in this session.
  set<string> session_excluded;  // by word_key
  set<string> shown_this_round;  // by word_key (to detect "all words gone through once")
};

enum class QuizMode { ShowWord = 1, ShowMeaningMaskWord = 2 };

static string masked_word(const string &w, std::mt19937_64 &rng) {
  if (w.size() <= 2) return w;
  std::uniform_int_distribution<int> dist_count(1, std::max<int>(1, static_cast<int>(w.size() / 2)));
  int hide_cnt = dist_count(rng);

  vector<int> positions;
  positions.reserve(w.size());
  for (int i = 0; i < static_cast<int>(w.size()); ++i) {
    unsigned char c = static_cast<unsigned char>(w[i]);
    if (std::isalpha(c) != 0) positions.push_back(i);
  }
  if (positions.empty()) return w;
  std::shuffle(positions.begin(), positions.end(), rng);
  hide_cnt = std::min(hide_cnt, static_cast<int>(positions.size()));

  string out = w;
  for (int i = 0; i < hide_cnt; ++i) out[positions[i]] = '_';
  return out;
}

static bool is_due(const WordEntry &e, int64_t now) {
  if (e.retired) return false;
  return now >= e.next_due_time;
}

static WordEntry *pick_next(WordBook &book, SessionState &session, int64_t now, bool force_not_due_allowed) {
  // Priority:
  // 1) key words due (excluding session_excluded)
  // 2) normal words due
  // 3) if no due tasks and user chooses to continue:
  //    pick not-due word with oldest last_review_time
  // In all cases: same tier -> farthest last_review_time first.

  auto all = book.all_mutable();

  auto best_in_group = [&](bool want_key, bool require_due) -> WordEntry * {
    WordEntry *best = nullptr;
    for (WordEntry *e : all) {
      if (e->retired) continue;
      if (e->is_key != want_key) continue;
      if (session.session_excluded.count(e->word_key)) continue;
      if (require_due && !is_due(*e, now)) continue;
      if (!best) {
        best = e;
        continue;
      }
      if (e->last_review_time < best->last_review_time) best = e;
    }
    return best;
  };

  if (WordEntry *e = best_in_group(true, true)) return e;
  if (WordEntry *e = best_in_group(false, true)) return e;

  if (!force_not_due_allowed) return nullptr;

  // continue mode: pick not-due with oldest last_review_time, key first
  if (WordEntry *e = best_in_group(true, false)) return e;
  if (WordEntry *e = best_in_group(false, false)) return e;
  return nullptr;
}

static void apply_answer(WordEntry &e, char ans, int64_t now, SessionState &session) {
  const auto &intervals = ebb_intervals_seconds();
  auto clamp_stage = [&]() {
    if (e.ebb_stage < 0) e.ebb_stage = 0;
    if (e.ebb_stage >= static_cast<int>(intervals.size()))
      e.ebb_stage = static_cast<int>(intervals.size()) - 1;
  };

  ans = static_cast<char>(std::tolower(static_cast<unsigned char>(ans)));
  e.review_count += 1;
  e.last_review_time = now;

  if (ans == 'y') {
    e.ebb_stage += 1;
    clamp_stage();
    e.next_due_time = now + intervals[e.ebb_stage];
    return;
  }

  if (ans == 'n') {
    // 不认识：重置遗忘曲线为初始状态（并尽快复习）
    e.ebb_stage = 0;
    clamp_stage();
    e.next_due_time = now + intervals[e.ebb_stage];
    return;
  }

  if (ans == 'k') {
    e.retired = true;
    e.next_due_time = std::numeric_limits<int64_t>::max() / 4;
    return;
  }

  if (ans == 't') {
    // 列为重点：本次会话不再抽查；并重置遗忘曲线
    e.is_key = true;
    session.session_excluded.insert(e.word_key);
    e.ebb_stage = 0;
    clamp_stage();
    e.next_due_time = now + intervals[e.ebb_stage];
    return;
  }
}

static string read_line_prompt(const string &prompt) {
  cout << prompt;
  cout.flush();
  string s;
  std::getline(cin, s);
  return s;
}

static void press_enter_to_continue() {
  cout << "按回车继续...";
  cout.flush();
  string dummy;
  std::getline(cin, dummy);
}

static void menu_add(WordBook &book) {
  string w = trim(read_line_prompt("输入英文单词: "));
  if (w.empty()) return;
  if (const WordEntry *ex = book.get_by_word(w)) {
    cout << "该单词已存在: " << ex->word << "\n";
    cout << "当前中文释义: " << ex->meaning_cn << "\n";
    cout << "将用新释义替换。\n";
  }
  string cn = trim(read_line_prompt("输入中文释义: "));
  if (cn.empty()) {
    cout << "中文释义为空，取消。\n";
    return;
  }
  WordEntry &e = book.add_or_replace(w, cn);
  cout << "已保存: " << e.word << " -> " << e.meaning_cn << "\n";
}

static void menu_search(const WordBook &book) {
  cout << "1) 按英文查找\n2) 按中文子串查找(打印所有包含该中文的单词)\n";
  string opt = trim(read_line_prompt("选择: "));
  if (opt == "1") {
    string w = trim(read_line_prompt("输入英文单词: "));
    const WordEntry *e = book.get_by_word(w);
    if (!e) {
      cout << "未找到。\n";
      return;
    }
    cout << e->word << " -> " << e->meaning_cn << "\n";
    cout << "最近背诵时间: " << format_time(e->last_review_time) << "\n";
    cout << "下次计划时间: " << format_time(e->next_due_time) << "\n";
    cout << "是否重点: " << (e->is_key ? "是" : "否") << "，是否退役: " << (e->retired ? "是" : "否") << "\n";
    cout << "背诵次数: " << e->review_count << "，阶段: " << e->ebb_stage << "\n";
  } else if (opt == "2") {
    string cn = read_line_prompt("输入中文内容(子串): ");
    auto list = book.find_by_chinese_substring(cn);
    if (list.empty()) {
      cout << "未找到。\n";
      return;
    }
    cout << "匹配到 " << list.size() << " 个单词(字典序):\n";
    for (const auto *e : list) {
      cout << "- " << e->word << " -> " << e->meaning_cn << "\n";
    }
  }
}

static void menu_list(const WordBook &book) {
  auto all = book.all();
  vector<const WordEntry *> v = all;
  sort(v.begin(), v.end(), [](const WordEntry *a, const WordEntry *b) { return a->word_key < b->word_key; });
  cout << "共 " << v.size() << " 个单词:\n";
  for (const auto *e : v) {
    cout << "- " << e->word << " -> " << e->meaning_cn;
    cout << " | 重点:" << (e->is_key ? "Y" : "N");
    cout << " | 退役:" << (e->retired ? "Y" : "N");
    cout << " | 最近:" << format_time(e->last_review_time);
    cout << " | 下次:" << format_time(e->next_due_time);
    cout << " | 次数:" << e->review_count;
    cout << "\n";
  }
}

static void dictation_loop(WordBook &book) {
  if (book.size() == 0) {
    cout << "词库为空，请先添加单词。\n";
    return;
  }

  cout << "默写模式:\n";
  cout << "1) 只给英文单词\n";
  cout << "2) 给中文释义 + 随机隐藏字母的英文单词\n";
  string opt = trim(read_line_prompt("选择(1/2): "));
  QuizMode mode = (opt == "2") ? QuizMode::ShowMeaningMaskWord : QuizMode::ShowWord;

  std::random_device rd;
  std::mt19937_64 rng((static_cast<uint64_t>(rd()) << 32) ^ static_cast<uint64_t>(now_epoch_seconds()));

  SessionState session;
  bool continue_when_done = false;

  auto should_start_new_round = [&]() -> bool {
    // If every non-retired word is shown in this round, start a new one.
    size_t active_cnt = 0;
    for (auto *e : book.all_mutable()) {
      if (!e->retired) active_cnt++;
    }
    return active_cnt > 0 && session.shown_this_round.size() >= active_cnt;
  };

  while (true) {
    int64_t now = now_epoch_seconds();

    WordEntry *e = pick_next(book, session, now, continue_when_done);
    if (!e) {
      cout << "当天所有单词背诵任务已完成。\n";
      cout << "输入 c 继续背诵(提前复习)，输入 q 返回主菜单: ";
      string s;
      std::getline(cin, s);
      s = trim(s);
      if (!s.empty() && (s[0] == 'c' || s[0] == 'C')) {
        continue_when_done = true;
        continue;
      }
      break;
    }

    if (should_start_new_round()) {
      session.shown_this_round.clear();
      session.session_excluded.clear();
      continue_when_done = false;
      cout << "本轮已完成，开始新的轮回（优先当前重点单词）。\n";
      continue;
    }

    session.shown_this_round.insert(e->word_key);

    cout << "\n============================\n";
    cout << "最近背诵时间: " << format_time(e->last_review_time) << "\n";
    cout << "下次计划时间: " << format_time(e->next_due_time) << (is_due(*e, now) ? " (已到)" : " (未到)") << "\n";
    cout << "重点: " << (e->is_key ? "是" : "否") << "\n";

    if (mode == QuizMode::ShowWord) {
      cout << "英文: " << e->word << "\n";
      cout << "中文: " << e->meaning_cn << "\n";
    } else {
      cout << "中文: " << e->meaning_cn << "\n";
      cout << "英文(隐藏部分字母): " << masked_word(e->word, rng) << "\n";
    }

    cout << "输入 y=认识, n=不认识, k=无需再次背诵, t=列为重点, q=退出默写: ";
    string ansline;
    std::getline(cin, ansline);
    ansline = trim(ansline);
    if (ansline.empty()) continue;
    char ans = ansline[0];
    if (ans == 'q' || ans == 'Q') break;

    // If word is both key & answered unrecognized, reset schedule to initial as required.
    apply_answer(*e, ans, now, session);
    if ((ans == 'n' || ans == 'N') && e->is_key) {
      e->ebb_stage = 0;
      e->next_due_time = now + ebb_intervals_seconds()[0];
    }

    cout << "背诵次数: " << e->review_count << "\n";
  }
}

static void menu_toggle_key(WordBook &book) {
  string w = trim(read_line_prompt("输入英文单词: "));
  WordEntry *e = book.get_by_word(w);
  if (!e) {
    cout << "未找到。\n";
    return;
  }
  e->is_key = !e->is_key;
  cout << e->word << " 重点标记已切换为: " << (e->is_key ? "是" : "否") << "\n";
}

static void menu_unretire(WordBook &book) {
  string w = trim(read_line_prompt("输入英文单词: "));
  WordEntry *e = book.get_by_word(w);
  if (!e) {
    cout << "未找到。\n";
    return;
  }
  e->retired = false;
  int64_t now = now_epoch_seconds();
  if (e->next_due_time > now + 365LL * 24 * 60 * 60) {
    e->next_due_time = now;
  }
  cout << e->word << " 已恢复到可背诵状态。\n";
}

static void print_main_menu() {
  cout << "\n========== 英语背单词 ==========\n";
  cout << "1) 添加/更新单词\n";
  cout << "2) 查找单词/中文检索\n";
  cout << "3) 开始默写\n";
  cout << "4) 列出所有单词\n";
  cout << "5) 手动切换重点标记\n";
  cout << "6) 取消退役(恢复背诵)\n";
  cout << "0) 保存并退出\n";
}

}  // namespace wordapp

int main() {
  using namespace wordapp;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  WordBook book("wordbook.db");
  if (!book.load()) {
    cout << "读取数据失败。\n";
  }

  while (true) {
    print_main_menu();
    string opt = trim(read_line_prompt("选择: "));
    if (opt == "1") {
      menu_add(book);
    } else if (opt == "2") {
      menu_search(book);
    } else if (opt == "3") {
      dictation_loop(book);
    } else if (opt == "4") {
      menu_list(book);
      press_enter_to_continue();
    } else if (opt == "5") {
      menu_toggle_key(book);
    } else if (opt == "6") {
      menu_unretire(book);
    } else if (opt == "0") {
      if (!book.save()) {
        cout << "保存失败（请检查当前目录写权限）。\n";
      } else {
        cout << "已保存到 wordbook.db\n";
      }
      break;
    }
  }
  return 0;
}

