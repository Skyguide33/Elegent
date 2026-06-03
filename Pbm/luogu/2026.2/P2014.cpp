//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[301], dp[301][301], n, m, tt; 

vector<int> e[301];

void dfs(int u) {
  for(int i = 1; i <= m; ++i) dp[u][i] = s[u];
  for(int v: e[u]) {
    dfs(v);
    for(int i = m; i >= 1; --i) {
      if(u == 0) dp[u][i] = max(dp[u][i], dp[v][i]); 
      for(int j = 1; j < i; ++j) {
        dp[u][i] = max(dp[u][i], dp[u][i-j]+dp[v][j]);
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> tt >> s[i];
    e[tt].push_back(i);
  }
  dfs(0);
  cout << dp[0][m] << endl;
  return 0;
}