//2025/10/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 2000005
const ll MOD = 20100403;

// 拓展欧几里得定理
ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = extend_gcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

// 带模快速幂
ll fast_power(ll b, ll p, ll mod) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%mod;
    b = (b*b)%mod;
    p >>= 1; 
  }
  return res;
}

// 逆元
ll mod_inverse(ll a, ll mod) {
  // ll x, y; extend_gcd(a, mod, x, y);
  // return (x%mod+mod)%mod;
  return fast_power(a, mod-2, mod);
}

ll fac[N], inv[N];
void init(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; ++i) {
    fac[i] = fac[i-1]*i%MOD;
    inv[i] = mod_inverse(fac[i], MOD);
  }
}

ll C(ll n, ll m) {
  return (fac[n]*inv[m]%MOD*inv[n-m]%MOD)%MOD;
}
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, m; cin >> n >> m;
  init(n+m);
  // cout << C(6, 4) << endl;
  cout << (C(n+m, m)-C(n+m, m-1)+MOD)%MOD << endl;
  return 0;
}