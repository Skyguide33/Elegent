//2026/3/5
#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl '\n'
#define N 151

struct Edge { int v, nxt; } e[10005];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[N], low[N], tot;

using PII = pair<int, int>;
priority_queue<PII, vector<PII>, greater<PII>> ans;

void tarjan(int u, int in_edg) {
  dfn[u] = low[u] = ++tot;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!dfn[v]) {
      tarjan(v, i);
      low[u] = min(low[u], low[v]);
      if(low[v] > dfn[u]) {
        if(u < v) ans.push({u, v});
        else ans.push({v, u});
      }
    } else if(i != (in_edg^1)) low[u] = min(low[u], dfn[v]);
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
  while(!ans.empty()) {
    auto [u, v] = ans.top(); ans.pop();
    cout << u << ' ' << v << endl;
  }
  return 0;
}