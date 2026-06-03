//2025/8/28
#include <stdio.h>

int ans, s[50005], d[50005];

int find_set(int &x) {
  if(x != s[x]) {
    int t = s[x];
    s[x] = find_set(s[x]);
    d[x] = (d[x]+d[t])%3;
  }
  return s[x];
}

void merge_set(int x, int y, int r) {
  int rootx = find_set(x), rooty = find_set(y);
  if(rootx == rooty) {
    if(r-1 != (d[x]-d[y]+3)%3) ++ans;
  } else {
    s[rootx] = rooty;
    d[rootx] = (r+d[y]-d[x]+2)%3;
  }
}

int main() {
  int n, k; scanf("%d %d", &n, &k);
  for(int i = 0; i <= n; ++i) { s[i] = i; d[i] = 0; }
  while(k--) {
    int d, x, y; scanf("%d %d %d", &d, &x, &y);
    if(x > n || y > n || (d == 2 && x == y)) { ++ans; }
    else merge_set(x, y, d);
  }
  printf("%d\n", ans);
  return 0;
}