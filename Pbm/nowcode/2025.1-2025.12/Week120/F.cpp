//2025/12/1 补题
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353

ll fast_power(ll b, ll p) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

ll pw[100005], a[100005];

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  ll n, l, r; cin >> n >> l >> r;
  char tt;
  for(int i = 1; i <= n; ++i) cin >> tt, a[i] = tt-'0';
  pw[0] = 1;
  for(int i = 1; i <= n; ++i) pw[i] = pw[i-1]*10%MOD;
  ll midl = (l+n-2)/n*n+1, midr = r/n*n;
  if(midl <= midr) {
    ll pre = 0, suf = 0, mid = 0;
    for(ll i = midr+1; i <= r; ++i) suf = (suf*10+a[(i-1)%n+1])%MOD;
    for(ll i = l; i < midl; ++i) pre = (pre*10+a[(i-1)%n+1])%MOD;
    pre = pre*fast_power(10, r-midl+1)%MOD;
    ll amod = 0;
    for(int i = 1; i <= n; ++i) amod = (amod*10+a[i])%MOD;
    mid = (fast_power(pw[n], (midr-midl+1)/n)-1)*amod%MOD*\
      fast_power((pw[n]-1+MOD)%MOD, MOD-2)%MOD*pw[r-midr]%MOD;
    cout << (pre+mid+suf)%MOD << endl;
  } else {
    ll ans = 0;
    for(ll i = l; i <= r; ++i) {
      ans = (ans*10+a[(i-1)%n+1])%MOD;
    }
    cout << ans << endl;
  }
}