//2026/5/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[400005];
int head[200005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = { v, w, head[u]};
  head[u] = ecnt;
}

ll dist[200005], pre[200005], vis[200005];

void dfs1(int u) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
    if(dist[v] != -1) continue;
    dist[v] = dist[u]+w;
    pre[v] = u;
    dfs1(v);
  }
}

ll dfs2(int u) {
  vis[u] = 1;
  ll res = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
    if(!vis[v]) res = max(res, w+dfs2(v));
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w); addedge(v, u, w);
  }
  int src = 0, des = 0;
  fill(dist, dist+n+1, -1);
  dist[1] = 0; 
  dfs1(1);
  for(int i = 1; i <= n; ++i) {
    if(dist[i] > dist[src]) src = i;
  }
  fill(dist, dist+n+1, -1);
  dist[src] = 0;
  dfs1(src);
  for(int i = 1; i <= n; ++i) {
    if(dist[i] > dist[des]) des = i;
  }
  cout << dist[des] << endl;
  pre[src] = 0;
  int u = des;
  while(u) {
    vis[u] = 1;
    u = pre[u];
  }
  u = pre[des];
  int l = src, r = des;
  bool flag = 1;
  while(u != src && flag) {
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(vis[v]) continue;
      ll d = dfs2(v)+w;
      if(d == dist[des]-dist[u]) {
        r = u;
        i = 0;
      }
      if(d == dist[u]) {
        l = u;
        i = 0;
        flag = 0;
      }
    }
    u = pre[u];
  }
  int ans = 0;
  while(r != l) {
    ++ans;
    r = pre[r];
  }
  cout << ans << endl;
  return 0;
}