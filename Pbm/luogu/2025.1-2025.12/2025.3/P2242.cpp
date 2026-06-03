//2025/3/7
#include <cstdio>
#include <algorithm>
using namespace std;

int a[15005];
bool cmp(int a, int b) { return a < b; }
int main() {
  int n, m, ans;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  ans = a[n-1]-a[0]+1;
  for(int i = n-1; i >= 0; i--) {
    a[i] -= a[i-1];
  }
  sort(a+1, a+n, cmp);
  for(int i = n-1; i > n-m; i--) {
    ans -= a[i]-1;
  }
  printf("%d\n", ans);
  return 0;
}