//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[500005];
int head[100005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}
int dfn[100005], low[100005], tot;
int stk[100005], instk[100005], top;
int scc[100005], cnt;
int idg[100005];

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u; instk[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(instk[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if(low[u] == dfn[u]) {
    ++cnt;
    int v;
    do {
      v = stk[top--]; instk[v] = 0;
      scc[v] = cnt;
    } while(v != u);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  for(int i = 1; i <= n; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  for(int u = 1; u <= n; ++u) {
    int su = scc[u];
    for(int i = head[u]; i; i = e[i].nxt) {
      int sv = scc[e[i].v];
      if(sv != su) ++idg[sv];
    }
  }
  int ans = 0;
  for(int i = 1; i <= cnt; ++i) {
    if(!idg[i]) ++ans;
  }
  cout << ans << endl;
  return 0;
}