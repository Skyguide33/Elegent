//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll extend_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll d = extend_gcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll x, y, m, n, L; cin >> x >> y >> m >> n >> L;
  ll c = x-y, a = L, b = n-m;
  if(b < 0) { b *= -1; c *= -1; }
  ll d = extend_gcd(a, b, x, y);
  if(c%d == 0) cout << ((y*c/d)%(a/d)+(a/d))%(a/d) << endl;
  else cout << "Impossible" << endl;
  return 0;
}