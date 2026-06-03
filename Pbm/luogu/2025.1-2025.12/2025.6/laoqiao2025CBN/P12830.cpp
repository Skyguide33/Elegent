//2025/6/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int a[2026], b[2026][2026], cnt, dp[2026][2026];

int lcm(int a, int b) {
  return (a*b) / __gcd(a, b);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 2025; ++i) {
    if(lcm(i, 2025) == 2025) a[++cnt] = i;
  }
  for(int i = 1; i <= cnt; ++i) {
    for(int j = 1; j <= cnt; ++j) {
      if(lcm(a[i], a[j]) == 2025) b[i][j] = 1;
    }
  }
  for(int i = 1; i <= cnt; ++i) dp[1][i] = 1;
  for(int i = 2; i <= 2025; ++i) {
    for(int j = 1; j <= cnt; ++j) {
      for(int k = 1; k <= cnt; ++k) {
        if(b[j][k]) {
          dp[i][j] = (dp[i][j]+dp[i-1][k]) % MOD;
        }
      }
      // cout << dp[i][j] << ' ';
    }
    // cout << endl;
  }
  ll ans = 0;
  for(int i = 1; i <= cnt; ++i) {
    ans += dp[2025][i];
  }
  cout << ans % MOD << endl;
  return 0;
}