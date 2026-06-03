//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

ll a[100005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  ll l = a[1];
  bool flag = 1;
  for(int i = 2; i <= n; ++i) {
    ll gd = gcd(l, a[i]);
    // cout << "l=" << l << endl;
    l = (l*a[i])/gd;
    if(l > 1e9) {
      flag = 0;
      break;
    }
  }
  if(flag) {
    flag = 0;
    for(int i = 1; i <= n; ++i) {
      if(a[i] == l) {
        flag = 1;
        break;
      }
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}