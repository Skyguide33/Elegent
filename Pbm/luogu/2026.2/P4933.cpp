//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[1005], dp[1005][40005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j <= 40000; ++j) dp[i][j] = 1;
  }
  ll ans = n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j < i; ++j) {
      int dis = a[i]-a[j];
      dp[i][dis+20000] = (dp[i][dis+20000]+dp[j][dis+20000])%MOD;
    }
    for(int j = 0; j <= 40000; ++j) ans = (ans+dp[i][j]-1)%MOD;
  }
  cout << ans << endl;
  return 0;
}