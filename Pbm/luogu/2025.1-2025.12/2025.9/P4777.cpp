//2025/8/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll m[100005], a[100005], n;

ll mod_mul(ll a, ll b, ll m) {
  ll res = 0;
  b %= m;
  while(b) {
    if(b&1) res = (res+a)%m;
    a = (a+a)%m;
    b >>= 1;
  }
  return res;
}

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = extend_gcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

ll excrt(const ll *a, const ll *m, const int n) {
  ll x, y;
  ll a1 = a[1], m1 = m[1];
  ll ans = (a1%m1+m1)%m1;
  for(int i = 2; i <= n; ++i) {
    ll a2 = a[i], m2 = m[i];
    ll a = m1, b = m2, c = (a2-a1%m2+m2)%m2;
    ll d = extend_gcd(a, b, x, y);
    if(c%d) return -1;
    x = mod_mul(x, c/d, b/d);
    ans = a1+x*m1;
    m1 = m2/d*m1;
    ans = (ans%m1+m1)%m1;
    a1 = ans;
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> m[i] >> a[i];
  cout << excrt(a, m, n) << endl;
  return 0;
}