//2026/2/6
#include <stdio.h>
#define max(x, y) ((x) > (y)? (x): (y))
#define min(x, y) ((x) < (y)? (x): (y))

int dp[1005], t[10005], c[10005], p[10005];

int main() {
  int srt_hh, srt_mm, ddl_hh, ddl_mm;
  int n; scanf("%d:%d %d:%d %d", &srt_hh, &srt_mm, &ddl_hh, &ddl_mm, &n);
  int tme = (ddl_hh-srt_hh)*60+ddl_mm-srt_mm;
  for(int i = 1; i <= n; ++i) scanf("%d %d %d", t+i, c+i, p+i);
  for(int i = 1; i <= n; ++i) {
    if(p[i]) {
      int tt = p[i], k = 1;
      while(tt) {
        k = min(tt, k);
        for(int j = tme; j >= k*t[i]; --j) dp[j] = max(dp[j], dp[j-k*t[i]]+k*c[i]);
        tt -= k;
        k <<= 1;
      }
    } else {
      for(int j = t[i]; j <= tme; ++j) dp[j] = max(dp[j], dp[j-t[i]]+c[i]);
    }
  }
  printf("%d\n", dp[tme]);
  return 0;
}