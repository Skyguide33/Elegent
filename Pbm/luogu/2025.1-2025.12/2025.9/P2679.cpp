//2025/9/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int MOD = 1000000007;

char a[1002], b[202];
int dp[202][202][1002][2];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  cin >> a >> b;
  for(int i = 0; i <= n; ++i) dp[0][0][i][0] = 1;
  bool v = 1;
  for(int i = 1; i <= m; ++i, v ^= 1) {
    if(i == 2) for(int i = 0; i <= n; ++i) dp[0][0][i][0] = 0;
    for(int j = 1; j <= k; ++j) {
      for(int l = 1; l <= n; ++l) {
        if(b[i-1] == a[l-1])
          dp[v][j][l][1] = ((dp[v^1][j][l-1][1]+dp[v^1][j-1][l-1][1])%MOD+dp[v^1][j-1][l-1][0])%MOD;
        else dp[v][j][l][1] = 0;
        dp[v][j][l][0] = (dp[v][j][l-1][0]+dp[v][j][l-1][1])%MOD;
      }
    }
  }
  cout << (dp[m%2][k][n][1]+dp[m%2][k][n][0])%MOD << endl;

  return 0;
}