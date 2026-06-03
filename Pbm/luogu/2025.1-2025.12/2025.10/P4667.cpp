//2025/10/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};  // 四个方向
const int ab[4] = {2, 1, 1, 2};
const int cd[4][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};
int graph[505][505], dis[505][505];
struct P { int x, y, dis; } u;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  memset(dis, 0x3f, sizeof(dis));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      char c; cin >> c;
      graph[i][j] = (c == '/'? 1: 2);
    }
  }
  deque<P> dq;
  dq.push_back({1, 1, 0});
  dis[1][1] = 0;
  while(!dq.empty()) {
    u = dq.front(); dq.pop_front();
    int nx, ny;
    for(int i = 0; i < 4; ++i) {
      nx = u.x+dir[i][0]; ny = u.y+dir[i][1];
      int d = 0;
      d = (graph[u.x+cd[i][0]][u.y+cd[i][1]] != ab[i]);
      if(nx && ny && nx < n+2 && ny < m+2 && dis[nx][ny] > dis[u.x][u.y]+d) {
        dis[nx][ny] = dis[u.x][u.y]+d;
        if(d == 0) dq.push_front({nx, ny, dis[nx][ny]});
        else dq.push_back({nx, ny, dis[nx][ny]});
        if(nx == n+1 && ny == m+1) break;
      }
    }
  }
  if(dis[n+1][m+1] != 0x3f3f3f3f) cout << dis[n+1][m+1] << endl;
  else cout << "NO SOLUTION" << endl;
  return 0;
}