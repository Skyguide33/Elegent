//2026/5/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[1000005], dp[1000005], pre[26];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) {
    char tt; cin >> tt;
    a[i] = tt-'a';
  }
  fill(dp, dp+n+1, 0);
  memset(pre, 0, sizeof(pre));
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    dp[i] = (dp[i-1]+dp[max(0, i-k-1)])%MOD;
    if(pre[a[i]]) {
      dp[i] = (dp[i]-dp[pre[a[i]]-1]+MOD)%MOD;
    }
    pre[a[i]] = max(1, i-k);
  }
  cout << dp[n]-1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}