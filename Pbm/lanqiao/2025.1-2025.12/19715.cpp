//2025/4/11
#include <bits/stdc++.h>
using namespace std;

int a[100005], diff[50005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n / 2; i++) {
    diff[i] = a[i] - a[n-i-1];
  }
  n /= 2;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    if(i + 1 < n) {
      if(1ll * diff[i] * diff[i+1] > 0) {
        int min_abs = min(abs(diff[i]), abs(diff[i+1]));
        ans += min_abs;
        if(diff[i] > 0) {
          diff[i] -= min_abs;
          diff[i+1] -= min_abs;
        } else {
          diff[i] += min_abs;
          diff[i+1] += min_abs;
        }
      }
    }
    ans += abs(diff[i]);
  }
  cout << ans << endl;
  return 0;
}