//2026/3/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005], c[200005], p[5];
ll dp[2][5];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  for(int i = 1; i <= n; ++i) cin >> c[i];
  int now = 0, pre = 1; 
  a[0] = INT_MAX>>1;
  dp[now][0] = 0;
  for(int i = 1; i <= n; ++i) {
    swap(now, pre);
    fill(dp[now], dp[now]+5, LONG_LONG_MAX>>1);
    p[0] = 2*c[i]; p[1] = c[i]; p[2] = 0; p[3] = b[i]; p[4] = 2*b[i];
    for(int j = max(0, 3-a[i]); j < 5; ++j) {
      for(int k = 0; k < 5; ++k) {
        if(a[i]+j-2 != a[i-1]+k-2) dp[now][j] = min(dp[now][j], dp[pre][k]+p[j]);
      }
    }
  }
  ll ans = LONG_LONG_MAX;
  for(int i = 0; i < 5; ++i) ans = min(ans, dp[now][i]);
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}