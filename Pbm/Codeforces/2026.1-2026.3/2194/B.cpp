//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n, x, y; cin >> n >> x >> y;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  ll wt = -1, maxi = 0, tt;
  for(int i = 1; i <= n; ++i) {
    tt = a[i]%x+a[i]/x*(x-y);
    // cout << tt << ' ';
    if(tt > wt) {
      maxi = i;
      wt = tt;
    }
  }
  // cout << endl;
  ll ans = a[maxi];
  // cout << "maxi=" << maxi << endl;
  for(int i = 1; i <= n; ++i) {
    if(i != maxi) {
      ans += a[i]/x*y;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}