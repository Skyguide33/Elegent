//2025/3/16
#include <iostream>
using namespace std;

int ans, n, m, edge[21][21], vis[21], len;
//

void dfs(int now) {
  for(int i = 1; i <= n; i++) {
    if(edge[now][i] != -1 && !vis[i]) {
      vis[i] = 1;
      int save[n+1];
      len += edge[now][i];
      dfs(i);
      len -= edge[now][i];
    }
  }
  ans = max(ans, len);
  vis[now] = 0;
  return;
}

int main() {
  cin >> n >> m;
  edge[0][0] = -1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= n; j++) edge[i][j] = -1;
  }
  while(m--) {
    int i, j, d;
    cin >> i >> j >> d;
    edge[i][j] = d;
    edge[j][i] = d;
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}