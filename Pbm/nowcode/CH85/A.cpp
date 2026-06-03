//2026/1/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, a, b; cin >> n >> a >> b;
  ll x;
  for(int i = 1; i <= n; ++i) {
    cin >> x;
    if(a == b) cout << 0 << ' ' << (x+b-1)/b << endl;
    else {
      ll cntb = (x+b-1)/b;
      ll minw = cntb*b-x;
      ll mina = 0, minb = cntb;
      for(int i = 1; cntb && i <= max(a, b); ++i) {
        --cntb;
        ll r = x-cntb*b;
        ll cnta = (r+a-1)/a;
        ll waste = cnta*a+cntb*b-x;
        if(waste < minw) {
          minw = waste;
          mina = cnta, minb = cntb;
        }
      }
      cout << mina << ' ' << minb << endl;
    }
  }

  return 0;
}