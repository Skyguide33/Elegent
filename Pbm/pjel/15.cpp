//2025/11/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll dp[21][21];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n = 20;
  for(int i = 0; i <= n; ++i) dp[i][0] = dp[0][i] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i-1][j]+dp[i][j-1];
    }
  }
  cout << dp[n][n] << endl;
  return 0;
}

// 137846528820