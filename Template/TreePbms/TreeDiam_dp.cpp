//2025/9/4 树的直径
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 100005;

int n;
struct edge { int to, w; };
vector<edge> e[N];
int dp[N];
int maxlen = 0;
bool vis[N];

void dfs(int u) {
  vis[u] = true;
  for(auto &x: e[u]) {
    if(vis[x.to]) continue;
    dfs(x.to);
    maxlen = max(maxlen, dp[u]+dp[x.to]+x.w);
    dp[u] = max(dp[u], dp[x.to]+x.w);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 0; i < n-1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    e[u].push_back({v, w}); e[v].push_back({u, w});
  }
  dfs(1);
  cout << maxlen << endl;
  return 0;
}