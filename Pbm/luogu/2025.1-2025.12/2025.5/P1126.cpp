//2025/5/23
#include <bits/stdc++.h>
using namespace std;

// 0 E  1 S  2 W  3 N
int step[52][52][4];
int a[52][52], dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

struct info{ int x, y, d; };

int main() {
  memset(step, 127, sizeof(step));
  cin.tie(0) -> sync_with_stdio(0);
  int N, M; cin >> N >> M;
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= M; ++j) cin >> a[i][j];
  }
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  char d; cin >> d; int dt = 0; 
  switch(d) {
    case 'E': { dt = 0;  break; }
    case 'S': { dt = 1;  break; }
    case 'W': { dt = 2;  break; }
    case 'N': { dt = 3;  break; }
  }

  queue<info> q; q.push({sx, sy, dt});
  step[sx][sy][dt] = 0;
  while(!q.empty()) {
    info now = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int add = 1;
      if(abs(now.d-i) == 2) ++add;
      if(now.d != i) ++add;
      for(int p = 1; p <= 3; ++p) {
        int nx=now.x+dx[i]*p, ny=now.y+dy[i]*p;
        if(nx<1 || ny<1 || nx>N-1 || ny>M-1) break;
        if(a[nx][ny]||a[nx+1][ny]||a[nx][ny+1]||a[nx+1][ny+1]) break;
        if(step[now.x][now.y][now.d]+add >= step[nx][ny][i]) continue;
        step[nx][ny][i] = step[now.x][now.y][now.d]+add;
        q.push({nx, ny, i});
      }
    }
  }
  int ans = 1e9;
  for(int i = 0; i < 4; ++i) ans = min(ans, step[tx][ty][i]);
  if(ans == 1e9) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}