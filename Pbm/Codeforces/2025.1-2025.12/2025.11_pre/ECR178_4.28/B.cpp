//2025/4/29
#include <bits/stdc++.h>
using namespace std;
#define N 200005

long long a[N], sum[N], maxa[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    memset(a, 0, sizeof(a));
    memset(maxa, 0, sizeof(maxa));
    memset(sum, 0, sizeof(sum));
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
      maxa[i] = maxa[i-1];
      if(a[i] > a[maxa[i-1]]) maxa[i] = i;
    }
    for(int i = n; i >= 1; --i) sum[i] = sum[i+1] + a[i];
    for(int i = n; i >= 1; --i) {
      long long ans;
      if(a[maxa[i-1]] > a[i]) ans = sum[i+1]+a[maxa[i-1]];
      else ans = sum[i];
      cout << ans << ' ';
    }
    cout << endl;
  }
  return 0;
}