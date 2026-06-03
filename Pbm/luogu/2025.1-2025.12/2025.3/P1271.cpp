//2025/3/16
#include <cstdio>
using namespace std;

int cnt[1000];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int t;
    scanf("%d", &t);
    cnt[t]++;
  }
  for(int i = 1; i <= 999; i++) {
    while(cnt[i]--) printf("%d ", i);
  }
  printf("\n");
  return 0;
}