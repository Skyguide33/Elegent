//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[100005][26];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n = s.length();
  s = ' '+s;
  int ans = 1e9;
  for(int d = 0; d < 26; ++d) {
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < 26; ++i) dp[0][i] = 0;
    for(int i = 1; i <= n; ++i) {
      int now = s[i]-'a';
      dp[i][now] = min(dp[i-1][(now+d)%26], dp[i-1][(now-d+26)%26]);
      for(int j = 0; j < 26; ++j) {
        if(j == now) continue;
        dp[i][j] = min(dp[i-1][(j+d)%26], dp[i-1][(j-d+26)%26])+1;
      }
    }
    for(int i = 0; i < 26; ++i) ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}