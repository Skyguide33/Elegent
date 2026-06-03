//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], dp[100005][31];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 31; ++j) dp[i][j] = dp[i-1][j];
    for(int j = 0; j < 31; ++j) {
      if(a[i]&(1<<j)) {
        for(int k = 0; k < 31; ++k) {
          if(a[i]&(1<<k)) dp[i][k] = max(dp[i][k], dp[i-1][j]+1);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < 31; ++i) ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}