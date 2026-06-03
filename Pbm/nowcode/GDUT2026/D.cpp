//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m, c; cin >> n >> m >> c;
  c /= 2;
  vector<vector<ll>> a(n+1, vector<ll>(m+1));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
  }
  int l = max(1, c-m), r = min(n, c-1);
  ll ans = 0;
  for(int row = l; row <= r; ++row) {
    int col = c-row;
    for(int i = row; i <= n; ++i) {
      for(int j = col; j <= m; ++j) {
        ans = max(ans, a[i][j]-a[i-row][j]-a[i][j-col]+a[i-row][j-col]);
      }
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