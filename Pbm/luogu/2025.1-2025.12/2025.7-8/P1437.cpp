//2025/8/21
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int int_min = INT_MIN/2;
  vector<vector<int>> a(n+1, vector<int> (n+1, 0));
  vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+2, vector<int>(n+1, int_min)));
  for(int i = 1; i <= n; ++i) 
    for(int j = i; j <= n; ++j) {
      cin >> a[i][j];
      a[i][j] += a[i-1][j];
    }
  dp[0][0][0] = 0;
  for(int k = 0; k <= m; ++k) 
    for(int j = 1; j <= n; ++j) {
      for(int i = j; i >= 0; --i) {
        if(i > 0 && k-i >= 0) dp[k][i][j] = max(dp[k][i][j], dp[k-i][i-1][j-1]+a[i][j]);
        dp[k][i][j] = max(dp[k][i][j], dp[k][i+1][j]);
      }
      dp[k][0][j] = max({dp[k][0][j], dp[k][1][j], dp[k][0][j-1]});
    }
  cout << max(dp[m][1][n], dp[m][0][n]) << endl;
  return 0;
}