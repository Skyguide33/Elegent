//2025/5/8
#include <bits/stdc++.h>
using namespace std;

int n, a[32][32];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct pos{ int x, y; };

void bfs(pos p) {
  queue<pos> q;
  q.push(p);
  while(!q.empty()) {
    pos now = q.front(); q.pop();
    a[now.x][now.y] = 0;
    for(int i = 0; i < 4; ++i) {
      int nx = now.x+dx[i], ny = now.y+dy[i];
      if(nx<0 || ny<0 || nx>n+1 || ny>n+1 || a[nx][ny]!=-1) continue;
      q.push({nx, ny});
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  memset(a, -1, sizeof(a));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      int t; cin >> t;
      if(t == 1) a[i][j] = 1;
    }
  }
  bfs({0, 0});
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(a[i][j] == -1) cout << "2 ";
      else cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}