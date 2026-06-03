//2025/6/6
#include <bits/stdc++.h>
using namespace std;

int n, m, a[355], b[5], dp[41][41][41][41];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) {
    int t; cin >> t;
    ++b[t];
  }
  for(int i = b[1]; i >= 0; --i) {
    for(int j = b[2]; j >= 0; --j) {
      for(int k = b[3]; k >= 0; --k) {
        for(int l = b[4]; l >= 0; --l) {
          int dist = 1+(b[1]-i)+2*(b[2]-j)+3*(b[3]-k)+4*(b[4]-l);
          dp[i][j][k][l] = max(max(dp[i+1][j][k][l],dp[i][j+1][k][l]),max(dp[i][j][k+1][l],dp[i][j][k][l+1]))+a[dist];
        }
      }
    }
  }
  cout << dp[0][0][0][0] << endl;
  return 0;
}