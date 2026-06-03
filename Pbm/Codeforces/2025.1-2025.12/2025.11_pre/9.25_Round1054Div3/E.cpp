//2025/9/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int a[200005];

void solve() {
  int n, k, l, r; cin >> n >> k >> l >> r;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int cnt = 0, cnt1 = 0;
  ll ans = 0;
  map<int, int> mp, mp1;
  int j = 0, j1 = 0;
  for(int i = 1; i <= n; ++i) {
    while(cnt < k && j <= n) {
      if(++j <= n)
        if(++mp[a[j]] == 1) ++cnt;
    }
    while(cnt1 <= k && j1 <= n) {
      if(++j1 <= n)
        if(++mp1[a[j1]] == 1) ++cnt1;
    }
    ans += max(0, min(j1-i, r)-max(j-i+1, l)+1);
    if(--mp[a[i]] == 0) --cnt;
    if(--mp1[a[i]] == 0) --cnt1;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}