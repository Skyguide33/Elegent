//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, e[101][101], dp[101][101];

void init() {
  for(int i = 1; i <= n; ++i) {
    fill(e[i]+1, e[i]+n+1, INT_MAX>>1);
    e[i][i] = 0;
  }
}

void addedge(int u, int v, int w) {
  e[u][v] = min(e[u][v], w);
  e[v][u] = min(e[v][u], w); // 若为有向边则删去此行
}

void floyd() {
  for(int i = 1; i <= n; ++i) copy(e[i]+1, e[i]+n+1, dp[i]+1);
  for(int k = 1; k <= n; ++k) 
    for(int i = 1; i <= n; ++i) 
      for(int j = 1; j <= n; ++j) 
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]); 
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  init();
  while(m--) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  floyd();
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) cout << dp[i][j] << ' ';
    cout << endl;
  }
  return 0;
}