//2025/3/8
#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int e[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  memset(e, 0x3f, sizeof(e));
  for(int i = 1; i <= n; i++) {
    e[i][i] = 0;
  }
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u][v] = min(e[u][v], w);
    e[v][u] = e[u][v];
  }
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
        e[i][j] = min(e[i][j], e[i][k]+e[k][j]);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << e[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}