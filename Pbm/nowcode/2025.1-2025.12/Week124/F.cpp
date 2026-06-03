//2025/12/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> a(n*2+1);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  if(n%2) {
    cout << "-1" << endl;
    return;
  }
  s = ' '+s+s;
  vector<vector<ll>> dp(n*2+1, vector<ll> (n*2+1, 1e16));
  for(int i = 2; i <= n*2; ++i) {
    if(s[i] == s[i-1]) dp[i-1][i] = a[i-1]*a[i];
  }
  for(int len = 4; len <= n; len += 2) {
    for(int r = len; r <= 2*n; ++r) {
      int l = r-len+1;
      if(s[l] == s[r]) dp[l][r] = dp[l+1][r-1]+a[l]*a[r];
      for(int k = l+1; k < r; k += 2) {
        dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
      }
    }
  }
  ll ans = 1e16;
  for(int i = n; i < 2*n; ++i) {
    ans = min(ans, dp[i-n+1][i]);
  }
  if(ans >= 1e16) cout << "-1" << endl;
  else cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}