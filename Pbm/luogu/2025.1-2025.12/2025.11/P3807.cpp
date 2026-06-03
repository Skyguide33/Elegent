//2025/11/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

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

ll fac[1000005], inv[1000005];

// 逆元
ll mod_inverse(ll a, ll mod) {
  if(0) {
    ll x, y; extend_gcd(a, mod, x, y);
    return (x%mod+mod)%mod;
  } else return fast_power(a, mod-2, mod);
}

void init(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; ++i) fac[i] = 1ll*fac[i-1]*i%n;
}

// 卢卡斯定理 (要求mod为素数且值较小<1e7)
ll C(ll n, ll m, ll mod) {
  if(m > n) return 0;
  return fac[n]*mod_inverse(fac[m], mod)%mod*mod_inverse(fac[n-m], mod)%mod;
}

ll Lucas(ll n, ll m, ll mod) {
  if(m == 0) return 1;
  return C(n%mod, m%mod, mod)*Lucas(n/mod, m/mod, mod)%mod;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int a, b, mod; cin >> a >> b >> mod;
    init(mod);
    cout << Lucas(a+b, a, mod) << endl;
  }
  return 0;
}

