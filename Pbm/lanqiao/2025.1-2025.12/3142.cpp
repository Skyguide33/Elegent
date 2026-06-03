//2025/3/26
#include <bits/stdc++.h>
using namespace std;

long long a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  // 操作1 p次, 操作2 k-p次
  // sum(a[n-p]:a[n-1]) + sum(a[0]:a[2k-2p-1])
  // a前缀和数组设为s[n], 则为 s[n-1]-s[n-p-1] + s[2k-2p-1]
  for(int i = 1; i < n; i++) a[i] += a[i-1];
  long long ans = 1e18;
  for(int p = 0; p <= k; p++) {
    ans = min(ans, a[n-1]-a[n-p-1]+a[2*(k-p)-1]);
  }
  cout << ans << endl;
  return 0;
}