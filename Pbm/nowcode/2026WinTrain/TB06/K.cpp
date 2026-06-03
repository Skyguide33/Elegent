//2026/2/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll m, n, z; cin >> m >> n >> z;
  ll res = z%(m+n);
  if(res > 0 && res <= m) cout << 0;
  else cout << 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}