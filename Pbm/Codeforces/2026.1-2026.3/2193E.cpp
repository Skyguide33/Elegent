//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[300005];

void solve() {
  int n; cin >> n;
  vector<int> dp(n+1, INT_MAX>>1);
  for(int i = 1; i <= n; ++i) cin >> a[i], dp[a[i]] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 2*i; j <= n; j += i) {
      dp[j] = min(dp[j], dp[i]+dp[j/i]);
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(dp[i] == INT_MAX>>1) cout << -1 << ' ';
    else cout << dp[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}