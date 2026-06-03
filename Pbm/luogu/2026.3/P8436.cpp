//2026/3/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005

struct Edge { int v, nxt; } e[4000005];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], tot;
int stk[N], top;
int bri[4000005];
vector<int> dcc[N];
// int dcc[N];
int cnt;

void tarjan(int u, int in_edg) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v, i);
      low[u] = min(low[u], low[v]);
      if(low[v] > dfn[u]) bri[i] = bri[i^1] = 1;
    } else if(i != (in_edg^1)) low[u] = min(low[u], dfn[v]);
  }
  if(dfn[u] == low[u]) {
    int v; ++cnt;
    do {
      v = stk[top--];
      // dcc[v] = cnt;
      dcc[cnt].push_back(v);
    } while(v != u);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  ecnt = 1;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  for(int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i, 0);
  cout << cnt << endl;
  for(int i = 1; i <= cnt; ++i) {
    cout << dcc[i].size() << ' ';
    for(int x: dcc[i]) cout << x << ' ';
    cout << endl;
  }
  return 0;
}