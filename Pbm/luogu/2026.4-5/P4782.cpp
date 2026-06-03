//2026/5/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 2000005

struct Edge { int v, nxt; } e[N];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], cnt;

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u; instk[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if(instk[v]) low[u] = min(low[u], dfn[v]);
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
  for(int k = 1; k <= m; ++k) {
    int i, a, j, b; cin >> i >> a >> j >> b;
    addedge(i+!a*n, j+b*n);
    addedge(j+!b*n, i+a*n);
  }
  for(int i = 1; i <= 2*n; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  for(int i = 1; i <= n; ++i) {
    if(scc[i] == scc[i+n]) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }
  cout << "POSSIBLE" << endl;
  for(int i = 1; i <= n; ++i) {
    if(scc[i] < scc[i+n]) cout << 0 << ' ';
    else cout << 1 << ' ';
  }
  cout << endl;
  return 0;
}