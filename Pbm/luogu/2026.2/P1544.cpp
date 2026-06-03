//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[101][101];
ll dp[101][101][101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  k = min(k, n);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= i; ++j) cin >> a[i][j];
  }
  memset(dp, 0xbf, sizeof(dp));
  dp[1][1][0] = a[1][1]; dp[1][1][1] = 3*a[1][1];
  for(int i = 2; i <= n; ++i) {
    for(int j = 1; j <= i; ++j) {
      for(int l = 0; l <= min(k, i); ++l) {
        if(l != 0) {
          if(j != i) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l-1]+3*a[i][j]);
          if(j != 1) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l-1]+3*a[i][j]);
        } 
        if(l != i) {
          if(j != i) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l]+a[i][j]);
          if(j != 1) dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l]+a[i][j]);
        }
      }
    }
  }
  ll ans = -1e18;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j <= k; ++j) ans = max(ans, dp[n][i][j]);
  }
  cout << ans << endl;
  return 0;
}