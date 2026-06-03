//2026/2/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[1005][1005], v[1005], w[1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
  for(int i = n; i >= 1; --i) {
    for(int j = m; j >= 1; --j) {
      dp[i][j] = dp[i+1][j];
      if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i+1][j-v[i]]+w[i]);
    }
  }
  int j = m;
  for(int i = 1; i <= n; ++i) {
    if(j >= v[i] && dp[i][j] == dp[i+1][j-v[i]]+w[i]) {
      cout << i << ' ';
      j -= v[i];
    }
  }
  cout << endl;
  return 0;
}