//2025/4/15
#include <iostream>
#include <cstring>
using namespace std;

int dp[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string a, b;
  while(cin >> a >> b) {
    memset(dp, 0, sizeof(dp));
    int n = a.length(), m = b.length();
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      }
    }
    cout << dp[n][m] << endl;
  }
  return 0;
}