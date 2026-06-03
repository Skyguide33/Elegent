//2025/12/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int l, r; cin >> l >> r;
  int m; cin >> m;
  ll sum = 1ll*(l+r)*(r-l+1)/2;
  while(m--) {
    int x; cin >> x;
    int sm = sum%x;
    if(sm) cout << 1 << endl;
    else cout << 0 << endl;
  }
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}