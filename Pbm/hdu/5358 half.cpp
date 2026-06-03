//2025/5/6
#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; a[i] += a[i-1];
  }
  long long ans = 0;
  for(int i = 0; i <= 34; ++i) {
    int idx = i;
    long long left = 1 << (idx-1), right = (1<<idx) - 1;
    if(idx == 0) idx = 1;
    int l = 1, r = 0;
    for(int j = 1; j <= n; ++j) {
      l = max(l, j);
      while(l <= n && a[l]-a[j-1] < left) ++l;
      r = max(r, l);
      while(r <= n && a[r]-a[j-1] <= right && a[r]-a[j-1] >= left) ++r;
      if(l > r) continue;
      ans += ((2ll*j+l+r-1)*(r-l)/2)*idx;
    }
  }
  cout << ans << endl;
  return 0;
}