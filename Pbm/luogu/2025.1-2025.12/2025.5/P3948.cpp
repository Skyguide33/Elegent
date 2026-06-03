//2025/5/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[80005], b[80005], c[80005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, opt, mod, min_n, max_n; 
  cin >> n >> opt >> mod >> min_n >> max_n;
  bool flag = 0;
  while(opt--) {
    char ch; ll l, r;
    cin >> ch >> l >> r;
    if(ch == 'A') {
      flag = 0;
      ll x; cin >> x;
      a[l] += x; a[r+1] -= x;
    } else {
      if(flag == 0) {
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for(ll i = 1; i <= n; ++i) {
          b[i] = b[i-1] + a[i];
          ll now = (b[i]*i) % mod;
          c[i] = c[i-1] + (min_n <= now && now <= max_n);
        }
        flag = 1;
      }
      cout << c[r] - c[l-1] << endl;
    }
  }
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  for(ll i = 1; i <= n; ++i) {
    b[i] = b[i-1] + a[i];
    ll now = (b[i]*i) % mod;
    c[i] = c[i-1] + (min_n <= now && now <= max_n);
  }
  ll f; cin >> f;
  while(f--) {
    ll l, r; cin >> l >> r;
    cout << c[r] - c[l-1] << endl;
  }
  return 0;
}