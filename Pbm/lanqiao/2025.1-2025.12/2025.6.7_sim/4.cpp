//2025/6/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  unordered_set<ll> s;
  for(ll n = 3; n <= 8; ++n) {
    for(ll i = 0; i < pow(10, n-3); ++i) {
      for(ll j = 0; j < pow(10, 8-n); ++j) {
        ll now = j*pow(10,n+1)+4931*pow(10,n-3)+i;
        if(s.find(now) == s.end()) s.insert(now);
      }
    }
  }
  ll ans = 0;
  ll l, r; cin >> l >> r;
  for(auto& x: s) {
    if(l <= x && x <= r) ans += x;
  }
  cout << ans << endl;
  return 0;
}