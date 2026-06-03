//2025/5/24
#include <bits/stdc++.h>
using namespace std;

int a[51];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int l = 1, r; cin >> r;
    for(int i = 1; i <= r; ++i) cin >> a[i];
    sort(a+1, a+r+1);
    int ans = 0;
    while(l < r && a[l]+a[r] % 2) {
      int lc = 1, rc = 1;
      for(;r-rc > l; ++rc) {
        if(a[r-rc] != a[r-rc+1]) break;
      }
      for(;l+lc < r; ++lc) {
        if(a[l+lc] != a[l+lc-1]) break;
      }
      if(lc < rc) {
        ans += lc;
        l += lc;
      } else {
        ans += rc;
        r -= rc;
      }
    }
    cout << ans << endl;
  }
  return 0;
}