//2026/5/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[500005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int maxlen = 0, maxl = 0, maxr = 0;
  for(int l = 1; l+2 <= n; ++l) {
    int r = lower_bound(a+1, a+n+1, a[l]+a[l+1])-a-1;
    // cout << "l r " << l << ' ' << r << endl;
    if(r-l+1 > maxlen) {
      maxlen = r-l+1;
      maxl = l, maxr = r;
    }
  }
  if(maxr-maxl+1 < 3) cout << 0 << endl;
  else {
    cout << maxr-maxl+1 << ' ';
    for(int i = maxl; i <= maxr; ++i) cout << a[i] << ' ';
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}