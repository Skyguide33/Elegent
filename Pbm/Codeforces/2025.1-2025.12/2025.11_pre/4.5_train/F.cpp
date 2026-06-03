//2025/4/5
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    int num[21], dp[21][21], mul[21];
    for(int i = 1; i <= n; i++) num[i] = s[i-1] - '0';
    memset(dp, 0, sizeof(dp));
    // 动态规划 dp[i][j] i双字符数字后一位的位置 j当前位置
    dp[1][1] = num[1];
    for(int i = 1; i <= n; i++) {
      dp[i][1] = num[1];
      for(int i = 1; i <= n; i++) mul[i] = i;
      for(int j = 2; j <= n; j++) {
        // cout << "test" << endl;
        if(j != i-1 && j != i) {
          int opt1, opt2;
          opt1 = dp[i][j-1] + num[j];
          opt2 = dp[i][mul[j-1]-1] + (dp[i][j-1]-dp[i][mul[j-1]-1])*num[j];
          if(opt1 < opt2) dp[i][j] = opt1;
          else {
            dp[i][j] = opt2;
            mul[j] = mul[j-1];
          }
        } else if(j == i-1) dp[i][j] = dp[i][j-1];
        else {
          int opt1, opt2;
          opt1 = dp[i][j-1] + (num[j-1]*10+num[j]);
          opt2 = dp[i][mul[j-2]-1] + (dp[i][j-2]-dp[i][mul[j-2]-1]) * (num[j-2]*10+num[j]);
          if(opt1 < opt2) dp[i][j] = opt1;
          else if(opt1 > opt2) {
            dp[i][j] = opt2;
            mul[j] = mul[j-2];
          } 
        }
      }
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) {
      ans = min(ans, dp[i][n]);
    }
    cout << ans << endl;
  }
  return 0;
}