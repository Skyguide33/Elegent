//2025/8/31
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

ll mod_inverse(ll a, ll m) {
  ll x, y;
  extend_gcd(a, m, x, y);
  return (x%m+m)%m;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll a, m; cin >> a >> m;
  cout << mod_inverse(a, m) << endl;
  return 0;
}