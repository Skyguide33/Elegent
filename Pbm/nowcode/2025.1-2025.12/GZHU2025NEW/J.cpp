//2026/3/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[2005][2005], dp[2005][2005][4];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

struct State { 
  int dist, x, y, d; 
  bool operator<(const State &B) const { return dist > B.dist; }
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> a[i][j]; 
  }
  memset(dp, 0x3f, sizeof(dp));
  priority_queue<State> q;
  dp[1][1][1] = dp[1][1][2] = 0;
  q.push({0, 1, 1, 1}); q.push({0, 1, 1, 2});
  while(!q.empty()) {
    auto [dist, x, y, d] = q.top(); q.pop();
    if(x == n && y == m) break;
    if(dist > dp[x][y][d]) continue;
    for(int i = 0; i < 4; ++i) {
      if((i-d+4)%4 == 2) continue;
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny]) continue;
      int n_dist = dp[x][y][d]+(i != d);
      if(n_dist < dp[nx][ny][i]) {
        dp[nx][ny][i] = n_dist;
        for(int j = 0; j < 4; ++j) {
          if((i-d)%2 == 0) continue;
          dp[nx][ny][j] = min(dp[nx][ny][j], dp[nx][ny][i]+1);
        }
        q.push({n_dist, nx, ny, i});
      } 
    }
  }
  cout << min(dp[n][m][1], dp[n][m][2]) << endl;
  return 0;
}