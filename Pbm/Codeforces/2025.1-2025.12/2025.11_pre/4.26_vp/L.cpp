//2025/4/29
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 0x3f3f3f3f
 
 
struct P{ long long p, l, r; } p[16];
struct edge{ long long to, w; };
struct node{ 
  long long id, dis; 
  bool operator < (const node& other) const { return dis > other.dis; }
};
vector<edge>e[N];
 
long long num[N], n, m, k, T;
long long dist[16][N];
bool final[N], gone[N], avail[N];
 
void Dijkstra() {
  memset(dist, 127, sizeof(dist));
  for(long long i = 1; i <= k; ++i) {
    memset(final, 0, sizeof(final));
    dist[i][p[i].p] = 0;
    priority_queue<node>q;
    q.push({p[i].p, dist[i][p[i].p]});
    while(!q.empty()) {
      node now = q.top(); q.pop();
      if(final[now.id]) continue;
      final[now.id] = 1;
      for(long long j = 0; j < e[now.id].size(); ++j) {
        edge& next = e[now.id][j];
        if(final[next.to]) continue;
        else {
          long long dis = dist[i][now.id] + next.w;
          if(dis < dist[i][next.to]) {
            dist[i][next.to] = dis;
            q.push({next.to, dist[i][next.to]});
          }
        }
      }
    }
  }
}
 
signed main() {
  cin.tie(0) -> sync_with_stdio(0);
   cin >> n >> m >> k >> T;
  for(long long i = 1; i <= n; ++i) cin >> num[i];
  for(long long i = 1; i <= k; ++i) {
    cin >> p[i].p >> p[i].l >> p[i].r;
  }
  for(long long i = 1; i <= m; ++i) {
    long long u, v, w; cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  Dijkstra();
  for(long long i = 1; i <= T; ++i) {
    long long ans = 0;
    memset(gone, 0, sizeof(gone));
    memset(avail, 0, sizeof(avail));
    for(long long j = 1; j <= k; ++j) {
      if(p[j].l <= i && p[j].r >= i) avail[j] = 1;
    }
    for(long long j = 1; j <= n; ++j) {
      long long mindis = INF;
      for(long long i = 1; i <= k; ++i) {
        if(avail[i] && dist[i][j] < mindis) {
          mindis = dist[i][j];
        }
      }
      ans += mindis * num[j];
    }
    cout << ans << endl;
  }
  return 0;
}