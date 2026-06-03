//2026/3/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1005

struct Edge { int v, w, nxt; } e[102005];
int head[N], ecnt;

inline void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int d[N], cur[N], n, s, t;

bool bfs() {
  fill(d+1, d+n+1, 0);
  d[s] = 1;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if(d[v] || !e[i].w) continue;
      d[v] = d[u]+1;
      if(v == t) return 1;
      q.push(v);
    }
  }
  return 0;
}

ll dfs(int u, ll mf) {
  if(u == t) return mf;
  ll sum = 0;
  for(int i = cur[u]; i; i = e[i].nxt) {
    cur[u] = i;
    int v = e[i].v;
    if(d[v] != d[u]+1 || !e[i].w) continue;
    int f = dfs(v, min(mf, 1ll*e[i].w));
    e[i].w -= f;
    e[i^1].w += f;
    sum += f;
    mf -= f;
    if(mf == 0) break;
  }
  if(!sum) d[u] = 0;
  return sum;
}

ll dinic() {
  ll flow = 0;
  while(bfs()) {
    copy(head+1, head+n+1, cur+1);
    flow += dfs(s, LONG_LONG_MAX>>1);
  }
  return flow;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, e; cin >> n >> m >> e;
  s = n+m+1; t = s+1;
  ecnt = 1;
  for(int i = 1; i <= e; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v+n, 1); addedge(v+n, u, 0);
  }
  for(int i = 1; i <= n; ++i) {
    addedge(s, i, 1); addedge(i, s, 0);
  }
  for(int i = n+1; i <= n+m; ++i) {
    addedge(i, t, 1); addedge(t, i, 0);
  }
  n += m+2;
  cout << dinic() << endl;
  return 0;
}