//2026/3/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[400005], b[400005];

void solve() {
  ll n, x; cin >> n >> x;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  ll minx = x, r1x = x;
  for(int i = 1; i <= n; ++i) {
    if(r1x >= a[i]) {
      minx = min(minx, r1x-a[i]);
      r1x -= a[i]-b[i];
    } else {
      cout << i-1 << endl;
      return;
    }
  }
  if(r1x >= x) {
    cout << "Infinity" << endl;
    return;
  }
  ll round = minx/(x-r1x)+1;
  ll ans = round*n;
  x -= round*(x-r1x);
  for(int i = 1; i <= n; ++i) {
    if(x >= a[i]) {
      x -= a[i]-b[i];
      ++ans;
    } else break;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}