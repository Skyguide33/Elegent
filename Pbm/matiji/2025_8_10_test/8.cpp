//2025/8/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  ll n, x, y, t; cin >> n >> x >> y;
  map<ll, ll> mp;
  for(ll i = 1; i <= n; ++i) {
    cin >> t;
    auto it = mp.find(t);
    if(it == mp.end()) mp[t] = 1;
    else ++it->second;
  }
  vector<pair<ll, ll>> m;
  ll maxnum = 0;
  for(auto& [i, j]: mp) {
    maxnum = max(maxnum, j);
    m.push_back({i, j});
  }
  ll ans = min(m.back().first*x, (n-maxnum)*y);
  ll ux, uy = 0;
  while(1) {
    uy += m.back().second*y;
    m.pop_back();
    if(uy >= ans) break;
    if(m.empty()) {
      ans = min(ans, uy);
    } else {
      ux = m.back().first*x;
      ans = min(ans, ux+uy);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; cin >> T;
  while(T--) solve();
  return 0;
}