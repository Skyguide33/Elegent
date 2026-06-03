//2025/3/11
#include <cstdio>

int N,M,T,SX,FX,SY,FY,a[6][11];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int dfs(int x, int y) {
  if(x == FX && y == FY) return 1;
  int ans = 0;
  a[x][y] = 1;
  for(int i = 0; i < 4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx <= 0 || ny <= 0 || nx > N || ny > M || a[nx][ny] == 1) continue;
    ans += dfs(nx,ny);
  }
  a[x][y] = 0;
  return ans;
}

int main() {
  scanf("%d %d %d %d %d %d %d", &N, &M, &T, &SX, &SY, &FX, &FY);
  while(T--) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[x][y] = 1;
  }
  printf("%d\n", dfs(SX,SY));
  return 0;
}