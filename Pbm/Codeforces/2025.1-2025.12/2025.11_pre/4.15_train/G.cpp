//2025/4/15
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    string s, t; cin >> s >> t;
    int idx = 0;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == '?') {
        if(idx < t.length()) s[i] = t[idx++];
        else s[i] = 'a';
      } else if(s[i] == t[idx]) idx++;
    }
    if(idx >= t.length()) cout << "YES" << endl << s << endl;
    else cout << "NO" << endl;
  }
  return 0;
}