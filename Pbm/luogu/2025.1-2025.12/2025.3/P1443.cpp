//2025/3/24
#include <bits/stdc++.h>
using namespace std;

struct node{ int x, y; };

int dx[8]={1,2,2,1,-1,-2,-2,-1}, dy[8]={2,1,-1,-2,-2,-1,1,2};
int p[401][401];

int main() {
  int n, m, x, y; scanf("%d %d %d %d", &n, &m, &x, &y);
  memset(p, -1, sizeof(p));
  p[x][y] = 0;
  queue<node>q;
  q.push({x, y});
  while(q.size()) {
    node now = q.front(); q.pop();
    for(int i = 0; i < 8; i++) {
      node next = {now.x+dx[i], now.y+dy[i]};
      if(next.x<1||next.y<1||next.x>n||next.y>m||p[next.x][next.y]!=-1) continue;
      p[next.x][next.y] = p[now.x][now.y] + 1;
      q.push(next);
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) printf("% -5d", p[i][j]);
    printf("\n");
  }
  return 0;
}