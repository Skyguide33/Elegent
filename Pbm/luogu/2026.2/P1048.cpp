//2026/2/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[1001];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t, m, w, v; cin >> t >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> w >> v;
    for(int j = t; j >= 1; --j) {
      if(j >= w) dp[j] = max(dp[j], dp[j-w]+v);
    }
  }
  cout << dp[t] << endl;
  return 0;
}