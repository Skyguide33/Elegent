//2025/4/3
#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    long long n, k, x, sum = 0; cin >> n >> k >> x;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i-1];
    }
    int r = x / a[n];
    x -= a[n] * r;
    long long ans;
    // cout << t << ' ' << r << ' ' << a[n] << ' ' << x << endl;
    if(a[n] < x) {
      ans = 0;
    } else {
      long long tag = a[n] - x;
      ans = n * (k-r-1) + upper_bound(a, a+n+1, tag) - a;
    }
    //if(ans < 0) ans = 0;
    cout << ans << endl;
  }
  return 0;
}