//2026/3/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m, a, b; cin >> n >> m >> a >> b;
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int c; cin >> c;
      if(!mp.contains(c)) mp[c] = 1;
      else ++mp[c];
    }
  }
  int tp = 0;
  vector<int> p;
  for(auto [x, y]: mp) {
    if(x != 0) p.push_back(y);
    else tp = y;
  }
  sort(p.begin(), p.end(), greater<int>());
  ll ans = 0, layer = 0;
  for(int x: p) {
    ll ap = 1ll*a*x, bp = 1ll*b*(tp+layer*x);
    if(ap <= bp) ans += ap;
    else {
      ans += bp;
      ++layer;
    }
    // cout << "x=" << x << ", op=" << (ap <= bp? 'a': 'b') << ", ans=" << ans << endl;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}