//2025/2/23
#include <stdio.h>
using namespace std;

long long times[1000005];
int main() {
  int n, k, kpos;
  long long max = 0, t;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n-1; i++) {
    scanf("%lld", &times[i]);
    times[i] += times[i-1];
  }
  for(int i = 0; i <= n-1; i++) {
    kpos = i+k;
    if(kpos > n) kpos = n;
    t = times[kpos]-times[i];
    if(t > max) {
      max = t;
    }
  }
  printf("%lld", times[n-1]-max);
  return 0;
}