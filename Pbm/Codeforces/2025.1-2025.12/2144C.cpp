//2025/11/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

void solve() {
  int n; cin >> n;
  vector<int> a(n+1), b(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  vector<array<int, 2>> dp(n+1);
  // dp[i][j] 指的是到第i个元素时不交换(j == 0)和交换(j == 1)的种类数
  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i) {
    if(a[i] >= a[i-1] && b[i] >= b[i-1]) dp[i][0] = (dp[i][0]+dp[i-1][0])%MOD;
    if(b[i] >= a[i-1] && a[i] >= b[i-1]) dp[i][1] = (dp[i][1]+dp[i-1][0])%MOD;
    if(a[i] >= b[i-1] && b[i] >= a[i-1]) dp[i][0] = (dp[i][0]+dp[i-1][1])%MOD;
    if(b[i] >= b[i-1] && a[i] >= a[i-1]) dp[i][1] = (dp[i][1]+dp[i-1][1])%MOD;
  }
  cout << (dp[n][0]+dp[n][1])%MOD << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}