//2025/4/
#include <bits/stdc++.h>
using namespace std;

int R, C, a[101][101], dp[101][101], len, ans, dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
struct pos{ int r, c; } p[10005];

void push(pos x) {
  p[++len] = x;
  int i = len;
  while(i >= 2) {
    if(a[p[i].r][p[i].c] < a[p[i/2].r][p[i/2].c]) {
      swap(p[i], p[i/2]);
      i /= 2;
    } else break;
  }
}

pos pop() {
  if(len == 0) return {0, 0};
  pos res = p[1];
  p[1] = p[len--];
  int i = 1;
  while(i * 2 <= len) {
    int son = i * 2;
    if(a[p[son].r][p[son].c] > a[p[son+1].r][p[son+1].c]) ++son;
    if(a[p[i].r][p[i].c] > a[p[son].r][p[son].c]) {
      swap(p[i], p[son]);
      i = son;
    } else break;
  }
  return res;
}

int dfs(pos now) {
  if(dp[now.r][now.c]) return dp[now.r][now.c];
  for(int i = 0; i < 4; ++i) {
    int nx = now.r+dx[i], ny = now.c+dy[i];
    if(nx < 1 || nx > R || ny < 1 || ny > C || a[nx][ny] >= a[now.r][now.c]) continue;
    dp[now.r][now.c] = max(dp[now.r][now.c], dfs({nx, ny}) + 1);
  }
  if(!dp[now.r][now.c]) ++dp[now.r][now.c];
  ans = max(ans, dp[now.r][now.c]);
  return dp[now.r][now.c];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> R >> C;
  for(int i = 1; i <= R; ++i) {
    for(int j = 1; j <= C; ++j) {
      cin >> a[i][j];
      push({i, j});
    }
  }
  while(len) dfs(pop());
  cout << ans << endl;
  return 0;
}