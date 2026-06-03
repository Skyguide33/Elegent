//2025/4/30
#include <bits/stdc++.h>
using namespace std;

struct edge{ int to, w; };
struct node{ 
  int id, dis;
  bool operator < (const node other) const { return dis > other.dis; } 
};
vector<edge> e[100005];

bool final[100005];
int dist[100005], pre[100005];

void dijkstra(int s) {
  memset(final, 0, sizeof(final));
  memset(pre, -1, sizeof(pre));
  priority_queue<node> q;
  dist[s] = 0; q.push({s, dist[s]});
  while(!q.empty()) {
    node now = q.top(); q.pop();
    if(final[now.id]) continue;
    final[now.id] = 1;
    for(int i = 0; i < e[now.id].size(); ++i) {
      edge next = e[now.id][i];
      if(final[next.to]) continue;
      int dis = dist[now.id] + next.w;
      if(dis < dist[next.to]) {
        dist[next.to] = dis;
        pre[next.to] = now.id;
        q.push({next.to, dist[next.to]});
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  memset(dist, 127, sizeof(dist));
  int n, m, s; cin >> n >> m >> s;
  for(int i = 1; i <= m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    e[a].push_back({b, c});
    // 无向图
    e[b].push_back({a, c});
  }
  dijkstra(s);
  for(int i = 1; i <= n; ++i) {
    cout << dist[i] << ' ';
  }
  cout << endl;
  return 0;
}