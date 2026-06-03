//2025/5/24
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
  if(a.length() == b.length()) return (a < b);
  return (a.length() > b.length());
} 

bool is_subseq(string s, string t) {
  int si = 0, ti = 0;
  for(; si < s.length(); ++si) {
    while(ti < t.length() && t[ti] != s[si]) ++ti;
    if(ti == t.length()) return 0;
  }
  return 1;
}

vector<string> ss;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    ss.clear();
    string s, t; cin >> s >> t;
    for(int i = 0; i < s.length(); ++i) {
      for(int j = i; j <= s.length(); ++j) {
        string subs = s.substr(i, j-i);
        if(is_subseq(subs, t)) {
          ss.push_back(subs);
        }
      }
    }
    sort(ss.begin(), ss.end(), cmp);
    cout << ss[0] << endl;
  }
  return 0;
}