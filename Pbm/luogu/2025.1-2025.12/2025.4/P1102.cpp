//2025/4/19
#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, c; cin >> n >> c;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  long long ans = 0;
  for(int i = 1, j = 1, k = 1; i <= n; ++i) {
    while(j <= n && a[j] - a[i] < c) ++j;
    while(k <= n && a[k] - a[i] <= c) ++k;
    if(a[j]-a[i] == c && k-1 >= 1) ans += k-j;
  }
  cout << ans << endl;
  return 0;
}