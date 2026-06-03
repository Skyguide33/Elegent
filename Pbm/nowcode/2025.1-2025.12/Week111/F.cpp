//2025/12/13
#include <cstdio>
 
int main() {
  int n, k; scanf("%d %d", &n, &k);
  k = (n-1-k)*2; 
  if(k < 0 || k > n-2) {
    printf("-1\n");
    return 0;
  }
  for(int i = 2; i <= k; i += 2) printf("%d %d ", i, i-1);
  for(int i = k+2; i <= n; ++i) printf("%d ", i);
  printf("%d\n", k+1);
}