//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<ll>> a(n+1, vector<ll>(m+1)), dp2(n+1, vector<ll>(m+1, LONG_LONG_MIN>>1));
  vector<vector<tuple<ll, ll, ll>>> dp1(n+1, vector<tuple<ll, ll, ll>>(m+1, {LONG_LONG_MIN>>1, 0, INT_MIN>>1}));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> a[i][j];
  }
  dp1[1][1] = {a[1][1], 0, a[1][1]};
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      // cout << "tag" << endl;
      auto [dist, pre, maxa] = dp1[i][j];
      if(i < n) {
        auto [o_dist, o_pre, o_maxa] = dp1[i+1][j];
        ll n_dist = dist+a[i+1][j];
        ll n_pre = 0, n_maxa = max(maxa, a[i+1][j]);
        if(n_dist < dist+a[i+1][j] || n_maxa > o_maxa) {
          dp1[i+1][j] = {n_dist, n_pre, n_maxa};
        }
      } 
      if(j < m) {
        auto [o_dist, o_pre, o_maxa] = dp1[i][j+1];
        ll n_dist = dist+a[i][j+1];
        ll n_pre = 1, n_maxa = max(maxa, a[i][j+1]);
        if(n_dist < dist+a[i][j+1] || n_maxa > o_maxa) {
          dp1[i][j+1] = {n_dist, n_pre, n_maxa};
        }
      }
    }
  }
  ll maxx = 0, maxy = 0, maxa = 0;
  int x = n, y = m;
  while(x > 0 && y > 0) {
    // cout << "x, y: " << x << ' ' << y << endl;
    if(a[x][y] > maxa) {
      maxa = a[x][y];
      maxx = x, maxy = y;
    }
    auto [_, pre, _] = dp1[x][y];
    if(pre == 0) --x;
    else --y;
  }
  if(maxx) a[maxx][maxy] *= -1;
  dp2[1][1] = a[1][1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(i < n) dp2[i+1][j] = max(dp2[i+1][j], dp2[i][j]+a[i+1][j]);
      if(j < m) dp2[i][j+1] = max(dp2[i][j+1], dp2[i][j]+a[i][j+1]);
    }
  }
  cout << dp2[n][m] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}