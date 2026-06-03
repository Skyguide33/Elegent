//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll dp[300005][2];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll x, y, z; cin >> x >> y >> z;
  string s; cin >> s;
  int n = s.length();
  s = ' '+s;
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for(int i = 1; i <= n; ++i) {
    if(s[i] == 'A') {
      dp[i][0] = min(dp[i-1][0]+y, dp[i-1][1]+z+y);
      dp[i][1] = min(dp[i-1][0]+z+x, dp[i-1][1]+x);
    } else {
      dp[i][1] = min(dp[i-1][1]+y, dp[i-1][0]+z+y);
      dp[i][0] = min(dp[i-1][1]+z+x, dp[i-1][0]+x);
    }
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
  return 0;
}