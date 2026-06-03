//2025/11/9
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

ll a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, m; cin >> n >> m;
  ll sum = 0;
  for(ll i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
  sum %= m;
  if(sum == 0) {
    cout << 0 << endl << 0 << ' ' << 0 << endl;
    return 0;
  }
  ll a = n, b = 1ll*n*(n+1)/2;
  ll g1 = gcd(a, b), g2 = gcd(g1, m);
  ll ans = sum%g2;
  ll s, d; 
  extend_gcd(a, b, s, d);
  ll k1, t;
  extend_gcd(g1, m, k1, t);
  k1 = k1*((ans-sum)/g2%m+m)%m;
  s = (s*k1%m+m)%m, d = (d*k1%m+m)%m;
  cout << ans << endl << s << ' ' << d << endl; 
  return 0;
}