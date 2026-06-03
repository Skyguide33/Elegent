//2026/6/2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

pair<int, int> p[1005];

int dp[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> p[i].first >> p[i].second;
    ans = max(ans, p[i].second);
  }
  sort(p+1, p+n+1);
  for(int j = 1; j <= n; ++j) {
    dp[j][j] = p[j].second;
    for(int i = j+1, now = i; i <= n; ++i) {
      dp[i][j] = dp[i-1][j]-p[i-1].second;
      while(now > 1 && 2*p[j].first <= p[i].first+p[now-1].first) {
        dp[i][j] = max(dp[i][j], dp[j][--now]);
      }
      dp[i][j] += p[i].second;
      ans = max(ans, dp[i][j]);
    }
  }
  for(int j = n; j >= 1; --j) {
    dp[j][j] = p[j].second;
    for(int i = j-1, now = i; i >= 1; --i) {
      dp[i][j] = dp[i+1][j]-p[i+1].second;
      while(now < n && 2*p[j].first >= p[i].first+p[now+1].first) {
        dp[i][j] = max(dp[i][j], dp[j][++now]);
      }
      dp[i][j] += p[i].second;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}