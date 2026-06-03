//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, w, nxt; } e[6005];
int head[3005], cnt; 

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int h[3005], d[3005], n, m, inf = 1e9;

bool spfa() {
  vector<int> vis(n+1, 1), cnt(n+1, 0);
  queue<int> q;
  for(int i = 1; i <= n; ++i) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if(h[v] > h[u]+w) {
        h[v] = h[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n) return 1;
        if(!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return 0;
}

void dijkstra(int s) {
  fill(d+1, d+n+1, inf);
  priority_queue<pair<int, int>> q;
  vector<int> final(n+1, 0);
  d[s] = 0; q.push({0, s});
  while(!q.empty()) {
    int u = q.top().second; q.pop();
    if(final[u]) continue;
    final[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if(final[v]) continue;
      int dis = d[u]+w;
      if(d[v] > dis) {
        d[v] = dis;
        q.push({-dis, v});
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  if(!spfa()) {
    for(int u = 1; u <= n; ++u) 
      for(int i = head[u]; i; i = e[i].nxt) 
        e[i].w += h[u]-h[e[i].to];
    for(int i = 1; i <= n; ++i) {
      dijkstra(i);
      ll ans = 0;
      for(int j = 1; j <= n; ++j) {
        if(d[j] == inf) ans += 1ll*inf*j;
        else ans += 1ll*j*(d[j]+h[j]-h[i]);
      }
      cout << ans << endl;
    }
  } else cout << -1 << endl;
  return 0;
}