//2025/5/10
#include <bits/stdc++.h>
using namespace std;

inline int read() {
  int x = 0, f = 1; char ch = getchar();
  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ '0'); ch = getchar(); }
  return x * f;
}

struct pos{ int x, y; };
int m, n,  c[102][102], cost[102][102], mark[102][102];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
// c 0 无色 1 红色 2 黄色 3 变红色 4 变黄色 5 变红=变黄 
int main() {
  memset(cost, 0x3f, sizeof(cost));
  cin.tie(0) -> sync_with_stdio(0);
  m = read(), n = read();
  while(n--) {
    int x = read(), y = read(); c[x][y] = read() + 1;
  }
  cost[1][1] = 0;
  queue<pos> q; q.push({1, 1});
  while(!q.empty()) {
    pos now = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int nx = now.x+dx[i], ny = now.y+dy[i];
      if(nx==0 || ny==0 || nx==m+1 || ny==m+1) continue;
      if(c[now.x][now.y] <= 2) {
        if(c[nx][ny] == 1 || c[nx][ny] == 2) {
          if(c[now.x][now.y] == c[nx][ny]) {
            if(cost[now.x][now.y] < cost[nx][ny]) {
              cost[nx][ny] = cost[now.x][now.y];
              q.push({nx, ny});
            }
          } else if(cost[now.x][now.y]+1 < cost[nx][ny]) {
            cost[nx][ny] = cost[now.x][now.y]+1;
            q.push({nx, ny});
          }
        } else if(c[nx][ny] == 0) {
          if(cost[now.x][now.y]+2 < cost[nx][ny]) {
            c[nx][ny] = c[now.x][now.y] + 2;
            cost[nx][ny] = cost[now.x][now.y] + 2;
            q.push({nx, ny});
          }
        } else if(c[nx][ny] >= 3) {
          if(cost[now.x][now.y]+2 < cost[nx][ny]) {
            c[nx][ny] = c[now.x][now.y] + 2;
            cost[nx][ny] = cost[now.x][now.y] + 2;
          } else if(cost[now.x][now.y]+2 == cost[nx][ny]) {
            if(c[nx][ny] != 5 && c[now.x][now.y]+2 != c[nx][ny]) c[nx][ny] = 5;
          }
        }
      } else if(c[nx][ny] == 1 || c[nx][ny] == 2) {
        if(c[now.x][now.y] == 5) cost[nx][ny] = min(cost[nx][ny], cost[now.x][now.y]);
        else {
          if(c[now.x][now.y] != c[nx][ny]+2) {
            if(cost[now.x][now.y]+1 < cost[nx][ny]) {
              cost[nx][ny] = cost[now.x][now.y]+1;
              q.push({nx, ny});
            }
          } else if(cost[now.x][now.y] < cost[nx][ny]) {
            cost[nx][ny] = cost[now.x][now.y];
            q.push({nx, ny});
          }
        }
      }
    }
    if(c[now.x][now.y] > 2) c[now.x][now.y] = 0;
  }
  if(cost[m][m] > 1e9) cout << -1 << endl;
  else cout << cost[m][m] << endl;
  return 0;
}