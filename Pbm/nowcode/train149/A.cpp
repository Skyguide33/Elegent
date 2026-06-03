//2026/3/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n, tt; cin >> n;
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    cin >> tt;
    mp[tt] = mp[tt]+1;
  }
  ll ans = 0;
  for(auto &[x, y]: mp) {
    if(y > 1) {
      ans += y-1;
      mp[x+1] = mp[x+1]+y-1;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}