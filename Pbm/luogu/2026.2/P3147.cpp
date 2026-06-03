//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[262145], dp[262145][2][2];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int pre = 1, now = 0;
  for(int i = 1; i <= n; ++i) cin >> dp[i][0][now], dp[i][1][now] = dp[i][0][now];
  for(int i = 1; i <= 39; ++i) {
    swap(pre, now);
    for(int j = 2; j <= n; ++j) {
      if(dp[j][0][pre] == dp[j-1][0][pre] || dp[j][0][pre] == dp[j-1][1][pre]) {
        dp[j][1][now] = dp[j][0][pre]+1;
      } else if(dp[j][1][pre] == dp[j-1][0][pre] || dp[j][1][pre] == dp[j-1][1][pre]) {
        dp[j][1][now] = dp[j][1][pre]+1;
      }
    }
    for(int j = n-1; j >= 1; --j) {
      if(dp[j][0][pre] == dp[j+1][0][pre] || dp[j][0][pre] == dp[j+1][1][pre]) {
        dp[j][0][now] = dp[j][0][pre]+1;
      } else if(dp[j][1][pre] == dp[j+1][0][pre] || dp[j][1][pre] == dp[j+1][1][pre]) {
        dp[j][0][now] = dp[j][1][pre]+1;
      }
    }
    for(int j = 1; j <= n; ++j) cout << dp[j][0][now] << ' ';
    cout << endl;
    for(int j = 1; j <= n; ++j) cout << dp[j][1][now] << ' ';
    cout << endl << endl;
  }
  int ans = 1;
  for(int i = 1; i <= n; ++i) ans = max({ans, dp[i][0][now], dp[i][1][now]});
  cout << ans << endl;
  return 0;
}