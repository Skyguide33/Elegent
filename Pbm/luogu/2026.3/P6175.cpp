
//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, e[101][101], dp[101][101], p[101][101], ans = INT_MAX>>2;

void init() {
  for(int i = 1; i <= n; ++i) {
    fill(e[i]+1, e[i]+n+1, INT_MAX>>2);
    e[i][i] = 0;
  }
}

void addedge(int u, int v, int w) {
  e[u][v] = min(e[u][v], w); // 取min防止防止重边长度覆盖最小值
  e[v][u] = min(e[v][u], w); // 若为有向边则删去此行
}

void floyd() {
  // 若需要保留原邻接矩阵, 则拷贝一份dp数组, 否则可直接在原邻接矩阵上操作
  for(int i = 1; i <= n; ++i) copy(e[i]+1, e[i]+n+1, dp[i]+1);
  for(int k = 1; k <= n; ++k) 
    for(int i = 1; i <= n; ++i) 
      for(int j = 1; j <= n; ++j) {
        if(i != j && i < k && j < k) ans = min(ans, dp[i][j]+e[i][k]+e[k][j]);
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]); // 仅记录路径长度
      }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  init();
  for(int i = 1; i <= m; ++i) {
    int u, v, d; cin >> u >> v >> d;
    addedge(u, v, d);
  }
  floyd();
  if(ans == INT_MAX>>2) cout << "No solution." << endl;
  else cout << ans << endl;
  return 0;
}