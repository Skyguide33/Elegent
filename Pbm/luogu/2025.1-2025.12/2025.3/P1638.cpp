//2025/3/5 逛画展
#include <stdio.h>
using namespace std;

int works[1000005], cnt[2005];

int main() {
  int n, m, ansl = 1, ansr, sum = 0, l = 1, r = 0;
  scanf("%d %d", &n, &m);
  ansr = n;
  for(int i = 1; i <= n; i++) scanf("%d", &works[i]);
  while(l <= n && r <= n) {
    if(sum == m) {
      if(r-l < ansr-ansl) {
        ansl = l;
        ansr = r;
      } 
      if(!(--cnt[works[l++]])) sum--;
    } else if(!(cnt[works[++r]])++) sum++;
  }
  printf("%d %d\n", ansl, ansr);
  return 0;
}