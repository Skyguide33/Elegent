//2025/4/22  邻接矩阵版本
#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 200005, INF = 0x3f3f3f3f;

struct node{ 
  int id, dis;
  bool operator < (const node &other) const { return dis > other.dis; }
};

int e[1005][1005];
int dist[N], pre[N];
bool final[N];

void dijkstra(int s, int n) {
  memset(dist, INF, sizeof(dist));
  priority_queue<node> q;
  dist[s] = 0; q.push({s, dist[s]});
  while(!q.empty()) {
    node now = q.top(); q.pop();
    if(final[now.id]) continue;
    final[now.id] = 1;
    for(int i = 1; i <= n; ++i) {
      if(e[now.id][i] == INF || final[i]) continue;
      int dis = dist[now.id] + e[now.id][i];
      if(dist[i] > dis) {
        dist[i] = dis;
        pre[i] = now.id;
        q.push({i, dist[i]});
      }
    }
  }
}

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
  // for(int i = 1; i <= n; ++i) {
  //   for(int j = 1; j <= n; ++j) cout << e[i][j] << ' ';
  //   cout << endl;
  // }
  dijkstra(s, n);
  for(int i = 1; i <= n; ++i) cout << dist[i] << ' ';
  cout << endl;
  return 0;
}