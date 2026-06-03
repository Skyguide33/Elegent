//2025/2/18
#include <bits/stdc++.h>
using namespace std;

int a[101], dp1[201][201], dp2[201][201];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  memset(dp1, 0x3f, sizeof(dp1));
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  for(int i = 1; i <= 2*n; ++i) {
    a[i] += a[i-1];
    dp1[i][i] = 0;
  }
  for(int len = 2; len <= n; ++len) {
    for(int l = 1; l+len-1 <= 2*n; ++l) {
      int r = l+len-1;
      for(int k = l; k < r; ++k) {
        dp1[l][r] = min(dp1[l][r], dp1[l][k]+dp1[k+1][r]+a[r]-a[l-1]);
        dp2[l][r] = max(dp2[l][r], dp2[l][k]+dp2[k+1][r]+a[r]-a[l-1]);
      }
    }
  }
  int ans1 = INT_MAX>>1, ans2 = 0;
  for(int i = 1; i <= n; ++i) {
    ans1 = min(ans1, dp1[i][i+n-1]);
    ans2 = max(ans2, dp2[i][i+n-1]);
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
}