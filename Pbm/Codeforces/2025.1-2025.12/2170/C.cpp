//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll n, k; cin >> n >> k;
  vector<ll> q(n+1), r(n+1);
  for(ll i = 1; i <= n; ++i) cin >> q[i];
  for(ll i = 1; i <= n; ++i) cin >> r[i];
  sort(q.begin()+1, q.end());
  sort(r.begin()+1, r.end());
  reverse(q.begin()+1, q.end());
  ll ans = 0;
  int pt = 1;
  for(ll i = 1; i <= n && pt <= n; ++i, ++pt) {
    ll y = r[i]+1;
    ll x = 1ll*q[pt]*y+r[i];
    // cout << x << ' ' << y << endl;
    while(pt < n && x > k) {
      ++pt;
      x = 1ll*q[pt]*y+r[i];
      // cout << "cr " << x << ' ' << y << endl;
    }
    if(x <= k) ++ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; cin >> T;
  while(T--) solve();
  return 0;
}