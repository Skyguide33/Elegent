//2025/7/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[26], cnt;

void solve() {
  string s; cin >> s;
  int len = s.length();
  int l = 0, r = 0;
  int ans = 1e9;
  while(r < len) {
    if(a[s[r]-'a'] == 0) ++cnt;
    ++a[s[r]-'a'];
    if(cnt == 26) {
      while(a[s[l]-'a'] > 1) {
        --a[s[l]-'a']; ++l;
      }
      ans = min(ans, r-l+1);
    }
    ++r;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}