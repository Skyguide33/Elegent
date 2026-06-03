//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, d; cin >> n >> d;
  ll mult = 1234567890999999999+1ll*d*1000000000;
  ll ans = mult/n;
  while(ans > 2e10) ans /= 10;
  cout << ans << endl;
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}