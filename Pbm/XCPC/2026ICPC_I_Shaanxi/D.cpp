//2026/5/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[500005];

void solve() {
  // cout << "tt" << endl;
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  ll r = m, x = 0, y = 1;
  for(int i = 1; i <= n; ++i) {
    ll t = (a[i]-x+y-1)/y;
    // cout << "t=" << t << endl;
    if(t <= r) {
      ll nx = x+y*t-a[i];
      if(nx+(r-t)*(y+1) > x+y*r) {
        r -= t;
        x = nx;
        y += 1;
      } else break;
    }
    // cout << x << ' ' << y << ' ' << r << endl;
    // cout << x+y*r << endl;
  }
  cout << x+y*r << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}