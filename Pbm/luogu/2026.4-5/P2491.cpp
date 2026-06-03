//2026/5/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[600005];
int head[300005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int dist[300005], pre[300005], vis[300005], maxd[300005];

void dfs1(int u) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
    if(dist[v] == -1) {
      dist[v] = dist[u]+w;
      pre[v] = u;
      dfs1(v);
    }
  }
}

int dfs2(int u) {
  int res = 0;
  vis[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v, w = e[i].w;
    if(!vis[v]) {
      res = max(res, w+dfs2(v));
    }
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, s; cin >> n >> s;
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
  pre[src] = 0;
  for(int i = 1; i <= n; ++i) {
    if(dist[i] > dist[des]) des = i;
  }
  int l = des, r = des;
  while(l) {
    vis[l] = 1;
    l = pre[l];
  }
  int ans = 1e9;
  l = des;
  deque<int> q;
  while(l) {
    while(!q.empty() && dist[q.front()]-dist[l] > s) q.pop_front();
    while(r != l && dist[r]-dist[l] > s) r = pre[r];
    for(int i = head[l]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(!vis[v]) maxd[l] = max(maxd[l], dfs2(v)+w);
    }
    while(!q.empty() && maxd[l] >= maxd[q.back()]) q.pop_back();
    q.push_back(l);
    ans = min(ans, max({dist[l], dist[des]-dist[r], maxd[q.front()]}));
    l = pre[l];
  }
  cout << ans << endl;
  return 0;
} 