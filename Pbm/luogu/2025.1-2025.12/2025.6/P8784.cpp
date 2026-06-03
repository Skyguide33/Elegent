//2025/6/14
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll n, dp[3][4];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  dp[0][0] = dp[0][3] = dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
  for(int i = 2; i <= n; ++i) {
    dp[i%3][0] = (dp[(i+2)%3][0] + dp[(i+1)%3][1] + dp[(i+1)%3][2] + dp[(i+1)%3][3]) % MOD;
    dp[i%3][1] = (dp[(i+2)%3][0] + dp[(i+2)%3][2]) % MOD;
    dp[i%3][2] = (dp[(i+2)%3][0] + dp[(i+2)%3][1]) % MOD;
    dp[i%3][3] = dp[i%3][0];
  }
  cout << dp[n%3][0] << endl;
  return 0;
}