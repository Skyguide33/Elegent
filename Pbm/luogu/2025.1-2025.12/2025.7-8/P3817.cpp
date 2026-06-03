//2025/7/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, x; cin >> n >> x;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    int sub = max(0, a[i]+a[i-1]-x);
    ans += sub;
    a[i] -= sub;
  }
  cout << ans << endl;
  return 0;
}