//2026/2/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, a, b, c; cin >> m >> n;
  map<int, vector<pair<int, int>>> mp;
  for(int i = 1; i <= n; ++i) {
    cin >> a >> b >> c;
    mp[c].push_back({a, b});
  }
  for(auto &[_, gp]: mp) {
    for(int j = m; j >= 1; --j) {
      for(auto [w, v]: gp) {
        if(j >= w) dp[j] = max(dp[j], dp[j-w]+v);
      }
    }
  }
  cout << dp[m] << endl;
  return 0;
}