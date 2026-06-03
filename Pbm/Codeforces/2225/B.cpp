//2026/4/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  string s; cin >> s;
  int len = s.length();
  int pos1 = -1, pos2 = -1;
  for(int i = 1; i < len; ++i) {
    if(s[i-1] == s[i]) {
      if(pos1 == -1) pos1 = i;
      else if(pos2 == -1) {
        pos2 = i;
        break;
      }
    }
  }
  if(pos1 != -1 && pos2 != -1) {
    for(int i = pos1; i < pos2; ++i) {
      if(s[i] == 'a') s[i] = 'b';
      else s[i] = 'a';
    }
    bool flag = 1;
    for(int i = 1; i < len; ++i) {
      if(s[i] == s[i-1]) {
        flag = 0;
        break;
      }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  } else cout << "YES" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}