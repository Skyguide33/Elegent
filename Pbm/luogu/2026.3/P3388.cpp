//2026/3/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 20005

struct Edge { int v, nxt; } e[200005];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], cut[N], tot, root;

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  int child = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
      if(low[v] >= dfn[u]) {
        ++child;
        if(child > 1 || u != root) cut[u] = 1;
      }
    } else low[u] = min(low[u], dfn[v]);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  for(int i = 1; i <= n; ++i) {
    if(!dfn[i]) {
      root = i;
      tarjan(i);
    }
  }
  stringstream ss;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(cut[i]) {
      ss << i << ' ';
      ans += cut[i];
    }
  }
  cout << ans << endl << ss.str() << endl;
  return 0;
}