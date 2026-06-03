//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll log22(ll x) {
  ll res = 0;
  while(x >= (1ll<<(res+1))) ++res;
  return res;
}

void solve() {
  ll n, q; cin >> n >> q;
  ll dep = log22(n)+1;
  // cout << "dep=" << dep << endl;
  while(q--) {
    ll x; cin >> x;
    ll depx = log22(x)+1;
    if(depx < dep) cout << (1ll<<(depx-1)) << endl;
    else cout << n-(1ll<<(dep-1))+1 << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}