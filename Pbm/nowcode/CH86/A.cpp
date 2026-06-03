//2026/3/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  string s, t; cin >> s >> t;
  bool flag1 = 0, flag2 = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '1') flag1 = 1;
    if(t[i] == '1') flag2 = 1;
    if(flag1 && flag2) break;
  }
  bool ans = 0;
  if(s == t) ans = 1;
  else if(n > 1) {
    if(!flag2) ans = 1;
    else if(flag1) {
      for(int i = 1; i < n; ++i) {
        if(t[i] == t[i-1]) {
          ans = 1;
          break;
        }
      }
    } 
  }
  cout << (ans? "YES": "NO") << endl;
  return 0;
}