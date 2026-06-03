//2026/5/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, x; cin >> n >> x;
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    ++mp[tt];
  }
  int ans = 0;
  for(auto [_, y]: mp) {
    if(y <= x) ans += y;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}