//2025/6/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll n, a[32][4][4];

void solve() {
  cin >> n;
  n -= 3;
  if(n <= 0) {
    cout << 1 << endl; 
    return;
  }
  ll pre[2][4] = {0, 1, 1, 1, 0, 1, 1, 1};
  ll now = 1, old = 0;
  for(ll i = 0; (1ll<<i) <= n; ++i) {
    if((1<<i) & n) {
      swap(now, old);
      for(ll j = 1; j <= 3; ++j) {
        pre[now][j] = 0;
        for(ll l = 1; l <= 3; ++l) {
          pre[now][j] = (pre[now][j] + (pre[old][l]*a[i][l][j])%MOD)%MOD;
        }
      }
    }
  }
  cout << pre[now][1] << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  a[0][1][1] = a[0][1][2] = a[0][2][3] = a[0][3][1] = 1;
  for(ll i = 1; i <= 31; ++i) {
    for(ll j = 1; j <= 3; ++j) {
      for(ll k = 1; k <= 3; ++k) {
        for(ll l = 1; l <= 3; ++l) {
          a[i][j][k] = (a[i][j][k]+(a[i-1][j][l]*a[i-1][l][k])%MOD)%MOD;
        }
      }
    }
  }
  ll T; cin >> T;
  while(T--) solve();
  // for(ll i = 1; i <= 3; ++i) {
  //   for(ll j = 1; j <= 3; ++j) cout << a[2][i][j] << ' ';
  //   cout << endl;
  // }
  return 0;
}