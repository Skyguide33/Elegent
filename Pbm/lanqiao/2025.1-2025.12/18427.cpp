//2025/6/14
#include <bits/stdc++.h>
using namespace std;

int dp[100005][2];
char s[100005][3];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> s[i];
  dp[1][0] = dp[1][1] = 2;
  for(int i = 2; i <= n; ++i) {
    if(s[i][0] == s[i-1][1]) dp[i][0] = min(dp[i-1][0]-1, dp[i-1][1]) + 2;
    else if(s[i][0] == s[i-1][0]) dp[i][0] = min(dp[i-1][1]-1, dp[i-1][0]) + 2;
    else dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + 2;
    if(s[i][1] == s[i-1][1]) dp[i][1] = min(dp[i-1][0]-1, dp[i-1][1]) + 2;
    else if(s[i][1] == s[i-1][0]) dp[i][1] = min(dp[i-1][1]-1, dp[i-1][0]) + 2;
    else dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 2;
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
  return 0;
}