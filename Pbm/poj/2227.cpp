//2025/9/
#include <iostream>
#include <queue>
using namespace std;
#define ll long long
#define endl '\n'

int a[302][302], n, m, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool vis[302][302];

struct pos {
  int x, y;
  bool operator < (const pos &b) const { return a[x][y] > a[b.x][b.y]; }
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> m >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> a[i][j];
  }
  priority_queue<pos> q;
  for(int i = 1; i <= n; ++i) {
    vis[i][1] = vis[i][m] = 1;
    q.push({i, 1}); q.push({i, m});
  }
  for(int j = 2; j < m; ++j) {
    vis[1][j] = vis[n][j] = 1;
    q.push({1, j}); q.push({n, j});
  }
  ll ans = 0;
  while(!q.empty()) {
    int x = q.top().x, y = q.top().y; q.pop();
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = dy[i]+y;
      if(nx < 1 || ny < 1 || nx > n || ny > m || vis[nx][ny]) continue;
      if(a[nx][ny] < a[x][y]) {
        ans += a[x][y]-a[nx][ny];
        a[nx][ny] = a[x][y];
      }
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  cout << ans << endl;
  return 0;
}