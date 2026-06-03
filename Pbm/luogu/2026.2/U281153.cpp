//2026/2/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[2][101][2]; 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  memset(dp, 0xbf, sizeof(dp));
  int now = 1, old = 0;
  dp[now][0][0] = 0;
  for(int i = 1; i <= n; ++i) {
    swap(now, old);
    int a; cin >> a;
    for(int j = 0; j <= k; ++j) {
      dp[now][j][0] = dp[old][j][0];
      if(j) dp[now][j][0] = max(dp[now][j][0], dp[old][j-1][1]+a);
      dp[now][j][1] = max(dp[old][j][1], dp[old][j][0]-a);
    }
  }
  int ans = 0;
  for(int i = 0; i <= k; ++i) ans = max(ans, dp[now][i][0]);
  cout << ans << endl;
  return 0;
}