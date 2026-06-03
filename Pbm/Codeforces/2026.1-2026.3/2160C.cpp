//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



void solve() {
  int n; cin >> n;
  string s;
  int cnt = 0;
  bool flag = 1;
  while(n) {
    if(n&1) {
      s.push_back('1');
      flag = 0;
    } else {
      s.push_back('0');
      if(flag) ++cnt;
    }
    n >>= 1;
  }
  for(int i = 0; i < cnt; ++i) s.push_back('0');
  // cout << s << endl;
  string t(s);
  reverse(t.begin(), t.end());
  int len = t.length();
  if(t == s && (len%2 == 0 || s[len/2] != '1')) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}