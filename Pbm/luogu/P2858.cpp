//2026/6/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[2005], dp[2005][2005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for(int l = 0; l <= n; ++l) {
    for(int r = n+1; r > l; --r) {
      int cnt = l+n-r+1;
      if(l > 0) dp[l][r] = dp[l-1][r]+cnt*a[l];
      if(r <= n) dp[l][r] = max(dp[l][r], dp[l][r+1]+cnt*a[r]);
      // cout << format("dp[{}][{}]={}", l, r, dp[l][r]) << ' ';
    }
    // cout << endl;
  }
  int ans = 0;
  for(int i = 0; i <= n; ++i) ans = max(ans, dp[i][i+1]);
  cout << ans << endl;
  return 0;
}