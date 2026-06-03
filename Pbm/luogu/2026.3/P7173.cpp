//2026/3/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 205

struct Edge { int v, w, c, nxt; } e[20405];
int head[N], ecnt;

inline void addedge(int u, int v, int w, int c) {
  e[++ecnt] = {v, w, c, head[u]};
  head[u] = ecnt;
}

inline void link(int u, int v, int w, int c) {
	addedge(u, v, w, c); addedge(v, u, 0, -c);
}

int n, s, t;
int d[N], cur[N], vis[N];

bool spfa() {
  fill(d+1, d+n+1, INT_MAX);
  queue<int> q;
  d[s] = 0;
  q.push(s);
  vector<int> inq(n+1, 0);
  while(!q.empty()) {
    int u = q.front(); q.pop(); inq[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      auto &[v, w, c, _] = e[i];
      if(w && d[u]+c < d[v]) {
        d[v] = d[u]+c;
        if(!inq[v]) {
          q.push(v);
          inq[v] = 1;
        }
      } 
    }
  }
  return d[t] < INT_MAX;
}

int dfs(int u, int mf, int &cost) {
  if(u == t) return mf;
  int flow = 0;
  vis[u] = 1; 
  for(int &i = cur[u]; i; i = e[i].nxt) {
    auto &[v, w, c, _] = e[i];
    if(vis[v] || !w || d[u]+c != d[v]) continue;
    int f = dfs(v, min(mf, w), cost);
    e[i].w -= f;
    e[i^1].w += f;
    mf -= f;
    flow += f;
    cost += f*c; 
    if(mf == 0) break;
  }
  vis[u] = 0; 
  if(!flow) d[u] = 0; 
  return flow;
}

pair<int, int> dinic() {
  int flow = 0, cost = 0;
  while(spfa()) {
    copy(head+1, head+n+1, cur+1); 
    flow += dfs(s, INT_MAX, cost);
  }
  return {flow, cost};
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m >> s >> t;
  ecnt = 1;
  int flow = 0, cost = 0;
  vector<int> revf(n+1, 0); 
  for(int i = 1; i <= m; ++i) {
    int u, v, w, c; cin >> u >> v >> w >> c;
    if(c >= 0) link(u, v, w, c);
    else {
      revf[u] -= w; revf[v] += w;
      cost += c*w;
      link(v, u, w, -c); 
    }
  }
  int sbak = s, tbak = t; 
  s = n+1, t = n+2; 
  for(int i = 1; i <= n; ++i) {
    if(revf[i] > 0) link(s, i, revf[i], 0);
    else if(revf[i] < 0) link(i, t, -revf[i], 0);
  }
  link(tbak, sbak, INT_MAX, 0);
  n += 2; 
  auto [A, B] = dinic();
  flow += e[ecnt].w; cost += B;
  e[ecnt].w = e[ecnt^1].w = 0;
  s = sbak, t = tbak;
  tie(A, B) = dinic();
  cout << flow+A << ' ' << cost+B << endl;
  return 0;
}