//2026/2/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int dp[1005], c[1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 0; i <= m; ++i) c[i] = 1;
  for(int i = 1; i <= n; ++i) {
    int v, w; cin >> v >> w;
    for(int j = m; j >= v; --j) {
      if(dp[j-v]+w > dp[j]) {
        dp[j] = dp[j-v]+w;
        c[j] = c[j-v];
      } else if(dp[j] == dp[j-v]+w) c[j] = (c[j]+c[j-v])%MOD;
    }
  }
  cout << c[m] << endl;
  return 0;
}