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

void solve() {
  int n, b; cin >> n >> b;
  ll x, y; 
  extend_gcd(b, 9973, x, y);
  cout << (x*n%9973+9973)%9973 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}