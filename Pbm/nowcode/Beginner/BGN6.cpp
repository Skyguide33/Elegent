//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s, t; cin >> s >> t;
  int lens = s.length(), lent = t.length();
  int ans = 1e9, cnt;
  for(int i = 0; i <= lent-lens; ++i) {
    cnt = 0;
    for(int j = 0; j < lens; ++j) {
      cnt += min(abs(s[j]-t[i+j]), 26-abs(s[j]-t[i+j]));
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}