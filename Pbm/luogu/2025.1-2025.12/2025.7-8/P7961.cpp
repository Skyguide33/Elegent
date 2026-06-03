//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 998244353;

int dp[102][31][31][16]; // 到第i个选项总共选了j个且当前S中有k个不能改变的1还有c个进位

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll C[31][31];
  for(int i = 0; i <= 30; ++i) {
    for(int j = 0; j <= i; ++j) {
      if(j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
    }
  }
  int n, m, K, v; cin >> n >> m >> K;
  dp[0][0][0][0] = 1;
  for(int i = 0; i <= m; ++i) {
    cin >> v;
    vector<ll> pow(n+1, 1);
    for(int j = 1; j <= n; ++j) pow[j] = pow[j-1]*v%MOD;
    for(int j = 0; j <= n; ++j) {
      for(int k = 0; k <= K; ++k) {
        for(int c = 0; c <= n/2; ++c) {
          // dp[i][j][k][c] ->
          if(dp[i][j][k][c] == 0) continue;
          for(int s = 0; s <= n-j; ++s) {
            int n_k = k+(s+c)%2;
            if(n_k > K) continue;
            int n_c = (s+c)>>1;
            dp[i+1][j+s][n_k][n_c] += dp[i][j][k][c]*pow[s]%MOD*C[n-j][s]%MOD;
            dp[i+1][j+s][n_k][n_c] %= MOD;
          }
        }
      }
    }
  }
  int ans = 0;
  for(int k = 0; k <= K; ++k) {
    for(int c = 0; c <= n/2; ++c) {
      if(__builtin_popcount(c)+k <= K) {
        ans += dp[m+1][n][k][c];
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}