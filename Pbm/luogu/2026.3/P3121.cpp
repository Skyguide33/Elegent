//2025/3/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005

struct Node {
  int son[26], fail, end, jmp, len;
} trie[N];

int cnt;

inline void Insert(const string &s, int idx) { 
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    if(!trie[now].son[ch]) {
      trie[now].son[ch] = ++cnt;
      trie[trie[now].son[ch]].len = trie[now].len+1;
    }
    now = trie[now].son[ch];
  }
  trie[now].end = 1;
  trie[now].jmp = now;
}

inline void getFail() {
  queue<int> q;
  for(int i = 0; i < 26; ++i) 
    if(trie[0].son[i]) q.push(trie[0].son[i]);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    for(int i = 0; i < 26; ++i) {
      if(trie[now].son[i]) {
        int v = trie[trie[now].fail].son[i];
        trie[trie[now].son[i]].fail = v; 
        if(!trie[now].jmp && trie[v].jmp) trie[now].jmp = trie[v].jmp;
        q.push(trie[now].son[i]);
      } else trie[now].son[i] = trie[trie[now].fail].son[i];
    }
  }
}

deque<pair<int, int>> q;

inline void query(const string &s) {
  int now = 0;
  for(int i = 0; s[i]; ++i) {
    int ch = s[i]-'a';
    now = trie[now].son[ch];
    q.push_back({i, now});
    if(trie[now].jmp) {
      int len = trie[trie[now].jmp].len;
      while(len--) q.pop_back();
      if(!q.empty()) now = q.back().second;
      else now = 0;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n; cin >> n;
  string t;
  for(int i = 1; i <= n; ++i) Insert((cin >> t, t), i);
  getFail();
  query(s);
  while(!q.empty()) {
    cout << s[q.front().first]; q.pop_front();
  }
  cout << endl;
  return 0;
}