//2025/3/9 3/10 rewrite
#include <cstdio>
#define ll long long

ll f[20][20], n;

#if 0
ll dfs(int i, int j) {
  if(f[i][j]) return f[i][j];
  if(i == 0) return 1;
  if(j > 0) f[i][j] += dfs(i, j-1);
  f[i][j] += dfs(i-1, j+1);
  return f[i][j];
}

int main() {
  scanf("%d", &n);
  printf("%lld\n", dfs(n, 0));
  return 0;
}
#endif

#if 1
int main() {
  scanf("%lld", &n);
  /*
    f[i][j] i入栈元素个数， j出栈元素个数。
    j == 0 f[i][0] == 1
    i > j 上一步可以是出栈，也可以是入栈 f[i][j]=f[i][j-1]+f[i-1][j];
    i == j 栈空，上一步只可能是出栈 f[i][j]==f[i][j-1];
    不存在i < j 的情况。
    i == n && j == n 循环结束
  */
  for(int i = 0; i <= n; i++) f[i][0] = 1;
  for(int j = 1; j <= n; j++) {
    for(int i = j; i <= n; i++) {
      f[i][j] = f[i][j-1];
      if(i > j) f[i][j] += f[i-1][j];
    }
  }
  printf("%lld\n", f[n][n]);
  return 0;
}
#endif