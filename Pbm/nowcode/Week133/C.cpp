//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll x, l, r; cin >> x >> l >> r;
  bool flag = 1;
  if(l <= x && x <= r) {
    cout << x << endl;
    flag = 0;
  }
  else if(x < l) {
    for(ll i = 1; x*i*i <= r; ++i) {
      ll c = x*i*i;
      if(l <= c && c <= r) {
        cout << c << endl;
        flag = 0;
        break;
      }
    }
  } else {
    for(ll i = 1; x/i/i >= l; ++i) {
      if(x%(i*i) == 0) {
        ll c = x/(i*i);
        if(l <= c && c <= r) {
          cout << c << endl;
          flag = 0;
          break;
        }
      }
    }
  }
  if(flag) cout << -1 << endl;
  return 0;
}