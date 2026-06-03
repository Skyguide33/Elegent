//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct info {
  int t, x, y;
} a[10005];

int dp[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> a[i].t >> a[i].x >> a[i].y;
  int ans = 0;
  for(int i = 1; i <= m; ++i) {
    dp[i] = 1;
    for(int j = 1; j < i; ++j) {
      if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) <= a[i].t-a[j].t) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}