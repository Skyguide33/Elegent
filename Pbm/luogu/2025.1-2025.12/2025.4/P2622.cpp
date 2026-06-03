//2025/4/28
#include <bits/stdc++.h>
using namespace std;

int a[101][11];
int dp[1025];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));
  int n, m; cin >> n >> m;
  int ans = -1;
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j) cin >> a[i][j];
  }
  dp[0] = 0; //tag: dp[(1>>n)-1]
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int now = q.front(); q.pop();
    // cout << "test" << endl;
    for(int i = 1; i <= m; ++i) {
      int idx = now;
      for(int j = 1; j <= n; ++j) {
        if(a[i][j] == 0) continue;
        else if(!(idx & 1<<(j-1)) && a[i][j] == 1) idx += 1<<(j-1);
        else if((idx & 1<<(j-1)) && a[i][j] == -1) idx -= 1<<(j-1);
      }
      int next = dp[now] + 1;
      if(dp[idx] == -1 || next < dp[idx]) {
        dp[idx] = next;
        q.push(idx);
      }
    }
  }
  if(dp[(1<<n)-1] > 0) ans = dp[(1<<n)-1];
  // for(int i = 0; i < 1<<n; ++i) cout << dp[i] << ' ';
  // cout << endl;
  cout << ans << endl;
  return 0;
}