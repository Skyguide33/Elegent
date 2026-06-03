//2026/3/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 201

struct Edge { int v, w, nxt; } e[2605];
int head[N], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int n, s, t;

int cur[N], d[N];

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

int dfs(int u, int mf) {
  if(u == t) return mf;
  int sum = 0;
  for(int i = cur[u]; i; i = e[i].nxt) {
    cur[u] = i;
    int v = e[i].v;
    if(d[v] != d[u]+1 || !e[i].w) continue;
    int f = dfs(v, min(mf, e[i].w));
    e[i].w -= f;
    e[i^1].w += f;
    mf -= f;
    sum += f;
    if(mf == 0) break;
  }
  if(!sum) d[u] = 0;
  return sum;
}

int dinic() {
  int flow = 0;
  while(bfs()) {
    copy(head+1, head+n+1, cur+1);
    flow += dfs(s, INT_MAX>>1);
  }
  return flow;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m >> s >> t;
  ecnt = 1;
  for(int i = 1; i <= n; ++i) {
    addedge(i, i+n, 1); addedge(i+n, i, 0);
  }
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u+n, v, 1); addedge(v, u+n, 0); 
    addedge(v+n, u, 1); addedge(u, v+n, 0); 
  }
  s += n;
  n *= 2;
  cout << dinic() << endl;
  return 0;
}