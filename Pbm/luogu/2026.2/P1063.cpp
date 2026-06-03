//2025/2/19
#include <bits/stdc++.h>
using namespace std;

int a[201], dp[201][201];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], a[i+n] = a[i];
  for(int len = 3; len <= n+1; ++len) {
    for(int l = 1; l+len-1 <= 2*n; ++l) {
      int r = l+len-1;
      for(int k = l+1; k < r; ++k) 
        dp[l][r] = max(dp[l][r], dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) ans = max(ans, dp[i][i+n]);
  cout << ans << endl;
  return 0;
}