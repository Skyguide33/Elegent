//2025/7/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[51];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  int ans = 50;
  for(int l = 1; l <= n; ++l) {
    for(int i = 1; i+l-1 <= n; ++i) {
      ans = min(ans, (a[i+l-1]-a[i-1])/l);
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}