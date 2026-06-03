//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005], dp[200005][25];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  memset(dp, 0x3f, sizeof(dp));
  cin >> a[1];
  dp[1][1] = a[1]+1;
  for(int i = 2; i <= m; ++i) {
    cin >> a[i];
    for(int j = 1; j <= 24; ++j) {
      dp[i][1] = min(dp[i][1], dp[i-1][j]+a[i]+1);
    }
    for(ll j = 2; j <= 24; ++j) {
      dp[i][j] = dp[i-1][j-1]+a[i]-a[i-1]+j*j*j*j-(j-1)*(j-1)*(j-1)*(j-1);
    }
  }
  ll ans = 1e18;
  for(int i = 1; i <= 24; ++i) ans = min(ans, dp[m][i]);
  cout << ans << endl;
  return 0;
}