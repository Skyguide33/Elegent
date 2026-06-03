//2025/4/22  邻接矩阵版本
#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 200005, INF = 0x3f3f3f3f;

int e[1005][1005];
bool vis[1005], final[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(e, INF, sizeof(e));
  int n, m, s; cin >> n >> m >> s;
  while(m--) {
    int a, b, c; cin >> a >> b >> c;
    e[a][b] = c;
    // 无向图
    e[b][a] = c;
  }
  vis[1] = 1;
  vector<int>
  for(int i = 1; i <= n; ++i) cout << dist[i] << ' ';
  cout << endl;
  return 0;
}