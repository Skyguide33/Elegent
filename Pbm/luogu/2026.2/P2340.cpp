//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[800005], s[401], f[401];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  memset(dp, 0xbf, sizeof(dp));
  dp[400000] = 0;
  for(int i = 1; i <= n; ++i) cin >> s[i] >> f[i];
  for(int i = 1; i <= n; ++i) {
    if(s[i] >= 0) {
      for(int j = 800000; j >= s[i]; --j) {
        dp[j] = max(dp[j], dp[j-s[i]]+f[i]);
      }
    } else {
      for(int j = 0; j <= 800000+s[i]; ++j) {
        dp[j] = max(dp[j], dp[j-s[i]]+f[i]);
      }
    }
    // for(int i = 399987; i <= 400016; ++i) {
    //   if(dp[i] < -1e5) cout << "-IF ";
    //   else cout << dp[i] << ' ';
    // }
    // cout << endl;
  }
  int ans = 0;
  for(int i = 400000; i <= 800000; ++i) {
    if(dp[i] >= 0) ans = max(ans, i+dp[i]-400000);
  }
  cout << ans << endl;
  return 0;
}