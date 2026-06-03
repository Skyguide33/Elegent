//2025/3/9
#include <cstdio>

struct pos{
  int x, y;
};

int a[15][15], m, n;
pos ans[10000000], src, des;
int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};
bool avail = 0;

void dfs(pos p, int top) {
  if(p.x == des.x && p.y == des.y) {
    avail = 1;
    for(int i = 0; i < top; i++) {
      printf("(%d,%d)->", ans[i].x, ans[i].y);
    }
    printf("(%d,%d)\n", des.x, des.y);
    return;
  }
  if(a[p.x][p.y] == 0) return;
  ans[top++] = p;
  a[p.x][p.y] = 0;
  for(int i = 0 ;i < 4; i++) {
    pos np={p.x+dx[i], p.y+dy[i]};
    if(np.x <= 0 || np.y <= 0|| np.x > m || np.y > n) continue;
    dfs(np, top);
  }
  a[p.x][p.y] = 1;
  return;
}

int main() {
  scanf("%d %d", &m, &n);
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  }
  scanf("%d %d %d %d", &src.x, &src.y, &des.x, &des.y);
  dfs(src, 0);
  if(!avail) printf("-1\n");
  return 0;
}

