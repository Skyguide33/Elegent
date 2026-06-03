//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  map<int, vector<pair<int, int>>> mp;
  int v, p, q;
  for(int i = 1; i <= m; ++i) {
    cin >> v >> p >> q;
    if(q) {
      if(mp[q].empty()) {
        mp[q].resize(2);
        mp[q][1] = {v, v*p};
      } else mp[q].push_back({v, v*p});
    } else {
      if(mp[i].empty()) mp[i].push_back({v, v*p});
      else mp[i][0] = {v, v*p};
    } 
  }
  m = mp.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1));
  int i = 0;
  for(auto &[label, item]: mp) {
    // cout << format("{0}", item) << endl;
    ++i;
    for(int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i-1][j];
      if(j >= item[0].first) dp[i][j] = max(dp[i][j], dp[i-1][j-item[0].first]+item[0].second);
      if(item.size() >= 2) {
        int c_sum = item[0].first+item[1].first, v_sum = item[0].second+item[1].second;
        if(j >= c_sum) dp[i][j] = max(dp[i][j], dp[i-1][j-c_sum]+v_sum);
      } 
      if(item.size() == 3) {
        int c_sum = item[0].first+item[2].first, v_sum = item[0].second+item[2].second;
        if(j >= c_sum) dp[i][j] = max(dp[i][j], dp[i-1][j-c_sum]+v_sum);
        c_sum += item[1].first; v_sum += item[1].second;
        if(j >= c_sum) dp[i][j] = max(dp[i][j], dp[i-1][j-c_sum]+v_sum);
      }
    } 
  }
  cout << dp[m][n] << endl;
  return 0;
}