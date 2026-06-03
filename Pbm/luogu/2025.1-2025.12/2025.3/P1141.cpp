//2025/3/9
#include <cstdio>
#include <cstring>

int x, y, m, n, ans[100005], f[1005][1005];
char s[1005][1005];

void dfs(int x, int y, bool c, int i) {
  if(x < 0 || y < 0 || x >= n || y >= n || f[x][y] != -1 || s[x][y]-'0' != c) return;
  f[x][y] = i; ans[i]++;
  dfs(x-1,y,!c,i); 
  dfs(x,y+1,!c,i);
  dfs(x+1,y,!c,i);
  dfs(x,y-1,!c,i);
  return;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%s", &s[i]);
  memset(f, -1, sizeof(f));
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    x--; y--;
    if(f[x][y] == -1) dfs(x,y,s[x][y]-'0',i);
    else ans[i] = ans[f[x][y]];
  }
  for(int i = 0; i < m; i++) printf("%d\n", ans[i]);
  return 0;
}