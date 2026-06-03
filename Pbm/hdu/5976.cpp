//2025/9/2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MOD = 1000000007;

ll f[50001];

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = extend_gcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

ll divm(ll a, ll b) {
  ll x, y;
  extend_gcd(b, MOD, x, y);
  return a%MOD*((x%MOD+MOD)%MOD)%MOD;
}

void init() {
  f[0] = 1;
  for(ll i = 1; i <= 50000; ++i) f[i] = f[i-1]*i%MOD;
}

void solve() {
  ll x; cin >> x;
  if(x <= 4) {
    cout << x << endl;
    return;
  }
  ll l = 0, r = 50000;
  while(l < r) {
    ll mid = (l+r+1)>>1;
    if(1ll*(mid+2)*(mid-1)/2 <= x) l = mid;
    else r = mid-1; 
  }
  ll left = 2, right = l, skip = 1;
  ll rest = x-(l+2)*(l-1)/2;
  if(rest == l) {
    ++left; right += 2; skip = right-1;
  } else if(rest != 0) {
    ++right; skip = right-rest;
  }
  ll ans = divm(divm(f[right], f[left-1]), skip);
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init();
  ll T = 1; cin >> T;
  while(T--) solve();
  return 0;
}