//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1), pre(n+1, 0);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    if(mp.contains(a[i])) pre[i] = mp[a[i]];
    mp[a[i]] = i;
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += 1ll*(i-pre[i])*(n-i+1)*(n-i+2)/2;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}