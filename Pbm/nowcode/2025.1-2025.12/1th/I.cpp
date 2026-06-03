//2025/9/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll INF = LONG_LONG_MAX>>3;

void solve() {
  int n; cin >> n;
  vector<ll> sum(n+1);
  for(int i = 1; i <= n; ++i) {
    cin >> sum[i];
    sum[i] += sum[i-1];
  }
  vector dp(n+1, vector<vector<pair<ll, ll>>>(n+1));
  auto get = [&] (int i, int j, ll b) -> ll {
    if(dp[i][j].empty() || dp[i][j][0].first > b) return INF;
    int l = 0, r = dp[i][j].size()-1;
    while(l < r) {
      int mid = (l+r+1)>>1;
      if(dp[i][j][mid].first <= b) l = mid;
      else r =mid-1;
    }
    return dp[i][j][l].second;
  };
  vector<ll> f(n+1);
  for(int i = 1; i <= n; ++i) dp[i][i].emplace_back(0, 0);
  for(int len = 2; len <= n; ++len) {
    for(int i = 1, j = i+len-1; j <= n; ++i, ++j) {
      ll lg = ceil(log2(sum[j]-sum[i-1]));
      for(int k = i; k < j; ++k) {
        ll l1 = sum[k]-sum[i-1], l2 = sum[j]-sum[k];
        ll b = abs(l1-l2);
        f[k] = get(i, k, b)+get(k+1, j, b)+lg*min(l1, l2);
        f[k] = min(f[k], INF);
        dp[i][j].emplace_back(b, f[k]);
      }
      ranges::sort(dp[i][j]);
      for(size_t l = 1; l < dp[i][j].size(); ++l)
        dp[i][j][l].second = min(dp[i][j][l].second, dp[i][j][l-1].second);
    }
    if(len == n) {
      for(int i = 1; i < n; ++i) cout << (f[i] >= INF? -1: f[i]) << ' ';
      cout << endl;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}