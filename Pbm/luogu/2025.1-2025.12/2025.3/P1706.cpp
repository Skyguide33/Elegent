//2025/3/5 3/9 rewrite
#include <cstdio>

int a[10], v[10], n, m;

void dfs(int step) {
  if(step == m+1) {
    for(int i = 1; i <= m; i++) printf("% 5d", a[i]);
    printf("\n");
    return;
  }
  for(int i = 1; i <= n; i++) {
    if(v[i] == 0) {
      a[step] = i;
      v[i] = 1;
      dfs(step+1);
      v[i] = 0;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  dfs(1);
  return 0;
}