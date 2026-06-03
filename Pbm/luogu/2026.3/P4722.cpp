//2026/3/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1201

struct Edge { int v, w, nxt; } e[240005];
int head[N], ecnt;

ll em[N][N];

inline void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int d[N], cur[N], n, s, t;

inline bool bfs() {
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
  for(int &i = cur[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(d[v] != d[u]+1 || !e[i].w) continue;
    int f = dfs(v, min(mf, e[i].w));
    e[i].w -= f; e[i^1].w += f;
    sum += f; mf -= f;
    if(mf == 0) break;
  }
  if(!sum) d[u] = 0;
  return sum;
}

inline int dinic() {
  int flow = 0;
  while(bfs()) {
    copy(head+1, head+n+1, cur+1);
    flow += dfs(s, INT_MAX);
  }
  return flow;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m >> s >> t;
  ecnt = 1;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    em[u][v] += w;
  }
  int ans = 0;
  for(int b = 28; b >= 0; b -= 4) {
    for(int i = 1; i < n; ++i) {
      for(int j = i+1; j <= n; ++j) {
        if((em[i][j] || em[j][i]) && (em[i][j] >= (1<<b) || em[j][i] >= (1<<b))) {
          addedge(i, j, em[i][j]%(1ll<<31));
          addedge(j, i, em[j][i]%(1ll<<31));
          em[i][j] = em[j][i] = 0;
        }
      }
    }
    ans += dinic();
  }
  cout << ans << endl;
  return 0;
}