//2025/6/4
#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1},
    dy[8] = {0,1,1,1,0,-1,-1,-1},
    fx[8] = {-2,7,-2,5,-2,3,-2,1},
    fy[8] = {-2,3,-2,1,-2,7,-2,5};

int a[12][12], v[12][12], n, k;
bool found = 0;

void dfs(int x, int y, int now, int cnt) {
  if(x == n-1 && y == n-1) {
    if(cnt == n*n) found = 1;
    return; 
  }
  int tag = (now+1) % k;
  for(int i = 0; i < 8; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx<0 || ny<0 || nx>n-1 || ny>n-1) continue;
    if(a[nx][ny] != tag) continue;
    if(v[nx][ny] >= 0) continue;
    if(v[nx][y]==fy[i] || v[x][ny]==fx[i]) continue;
    v[x][y] = i;
    dfs(nx, ny, tag, cnt+1);
    if(found) return;
    v[x][y] = -1;
  }
}

int main() {
  memset(v, -1, sizeof(v));
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) cin >> a[i][j];
  }
  dfs(0, 0, a[0][0], 1);
  int x = 0, y = 0;
  if(v[x][y] == -1) cout << v[x][y];
  while(v[x][y] != -1) {
    int d = v[x][y];
    cout << d;
    x += dx[d]; y += dy[d];
  }
  cout << endl;
  return 0;
}