//2025/4/9
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int dp[10000005][5];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N; cin >> N;
  dp[1][0]=dp[2][1]=dp[2][2]=dp[2][3]=dp[2][4]=1, dp[2][0]=2;
  for(int i = 3; i <= N; i++) {
    dp[i][1] = (dp[i-2][0]+dp[i-1][2]) % MOD;
    dp[i][2] = (dp[i-2][0]+dp[i-1][1]) % MOD;
    dp[i][3] = dp[i][4] = dp[i-2][0];
    dp[i][0] = ((dp[i][3]+dp[i-1][0])%MOD+(dp[i-1][1]+dp[i-1][2])%MOD) % MOD;
  }
  cout << dp[N][0] << endl;
  return 0;
}