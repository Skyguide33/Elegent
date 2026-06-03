//2025/7/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> e2;

void solve() {
  ll t = 1;
  for(int i = 0; i < 32; ++i) {
    e2.insert(t); t *= 2;
  }
  ll x, y; cin >> x >> y;
  ll g =  __gcd(x, y);
  x /= g, y /= g;
  if((x+y) % 2) {
    cout << -1 << '\n';
    return;
  }
  bool s = 0;
  if(e2.find(x+y) != e2.end()) s = 1;
  set<pair<ll, ll>> a;
  a.insert({x, y});
  int ans = 0;
  while(1) {
    if(x == y) {
      cout << ans + 1 << '\n';
      return;
    } else if(x < y) {
      y -= x; x *= 2;
    } else {
      x -= y; y *= 2;
    }
    cout << x << ' ' << y << ' ' << x-y << '\n';
    if(a.find({x, y}) != a.end() || (!s && e2.find(abs(x-y)) != e2.end())) {
      cout << -1 << '\n';
      return;
    } else {
      a.insert({x, y});
      ++ans;
    }
    cout << x << ' ' << y << ' ' << x-y << '\n';
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}