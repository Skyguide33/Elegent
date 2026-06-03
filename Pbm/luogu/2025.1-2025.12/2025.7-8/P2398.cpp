//2025/8/27
#include <stdio.h>

long long f[100005];

int main() {
  long long n, ans = 0; scanf("%lld", &n);
  for(int i = n; i; --i) {
    f[i] = (n/i)*(n/i);
    for(int j = i<<1; j <= n; j += i) f[i] -= f[j];
    ans += f[i]*i;
  }
  printf("%lld\n", ans);
  return 0;
}