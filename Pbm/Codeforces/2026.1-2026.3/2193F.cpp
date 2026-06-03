//2026/3/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int x[200005];
int p[200005][2];

void solve() {
  int n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
  map<int, pair<int, int>> mp;
  for(int i = 1; i <= n; ++i) cin >> x[i];
  for(int i = 1; i <= n; ++i) {
    int y; cin >> y;
    if(!mp.contains(x[i])) mp[x[i]] = {y, y};
    else {
      mp[x[i]].first = min(mp[x[i]].first, y);
      mp[x[i]].second = max(mp[x[i]].second, y);
    }
  }
  n = 0;
  p[0][0] = p[0][1] = ay;
  for(auto [x, y]: mp) {
    auto [miny, maxy] = y;
    p[++n][0] = miny;
    p[n][1] = maxy;
  }
  ++n;
  p[n][0] = p[n][1] = by;
  vector<vector<ll>> dp(n+1, vector<ll>(2));
  for(int i = 1; i <= n; ++i) {
    dp[i][0] = min(dp[i-1][0]+abs(p[i][1]-p[i-1][0]), dp[i-1][1]+abs(p[i][1]-p[i-1][1]))+p[i][1]-p[i][0];
    dp[i][1] = min(dp[i-1][0]+abs(p[i][0]-p[i-1][0]), dp[i-1][1]+abs(p[i][0]-p[i-1][1]))+p[i][1]-p[i][0];
  }
  cout << bx-ax+min(dp[n][0], dp[n][1]) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}