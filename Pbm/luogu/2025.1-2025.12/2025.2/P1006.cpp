//2025/2/20
#include <stdio.h>
#define rint register int

inline int max(const int& a, const int& b) {
  if(a > b) return a;
  return b;
}

int a[51][51], f[51][51][51][51] = {};

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  for(rint i = 1; i <= m; i++) {
    for(rint j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  }
  for(rint i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      for(rint k = 1; k <= m; k++) {
        for(rint l = 1; l <= n; l++) {
          f[i][j][k][l] = max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
          if(i == k && j == l) f[i][j][k][l] -= a[i][j];
        }
      }
    }
  }
  printf("%d", f[m][n][m][n]);
  return 0;
}