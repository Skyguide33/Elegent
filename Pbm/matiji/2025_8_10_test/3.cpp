//2025/8/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int s[500005];
ll dp[500005][3];

void solve() {
  memset(dp, 0, sizeof(dp));
  ll n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> s[i];
  s[0] = s[1];
  dp[0][0] = dp[0][1] = 1;
  dp[0][2] = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i-1][0]; // 填0
    if(s[i] != s[i-1]) {
      dp[i][0] += dp[i-2][0];
    }
  }
  for(int i = 0; i < 3; ++i) {
    for(int j = 1; j <= n; ++j) cout << dp[j][i] << ' ';
    cout << endl;
  }
  cout << endl;
  // cout << dp[n][0] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}