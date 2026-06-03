//2026/3/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int l = 1, r = n; 
  auto check = [n, k, m](int mid)->bool {
    // cout << "mid=" << mid << endl;
    int res = INT_MAX>>1;
    for(int i = max(1, k-n+1); i <= min(n-mid+1, k); ++i) {
      int l = i, r = i+mid-1, cnt = 0, rst = 1;
      if(l < k) {
        cnt += (k-l-1)+(k-l);
        rst = k-l;
      }
      if(k < r) {
        if(rst >= r-k) cnt += r-k;
        else cnt += (r-k-rst)+(r-k);
      }
      res = min(res, cnt);
      // cout << "l=" << l << ", r=" << r << ", cnt=" << cnt << endl;
    }
    return res <= m;
  };
  while(l < r) {
    int mid = (l+r+1)>>1;
    if(check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
} 