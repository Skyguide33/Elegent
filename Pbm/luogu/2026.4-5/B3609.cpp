//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[100005];
int head[10005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dfn[10005], low[10005], tot;
int stk[10005], instk[10005], top;
int scc[10005], cnt;

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
    if(u != v) addedge(u, v);
  }
  for(int i = 1; i <= n; ++i) {
    if(!dfn[i]) tarjan(i);
  }
  map<int, vector<int>> mp;
  for(int i = 1; i <= n; ++i) {
    mp[scc[i]].push_back(i);
  }
  for(int i = 1; i <= cnt; ++i) sort(mp[i].begin(), mp[i].end());
  cout << cnt << endl;
  for(int i = 1; i <= n; ++i) {
    if(!mp[scc[i]].empty()) {
      for(int x: mp[scc[i]]) cout << x << ' ';
      cout << endl;
      mp[scc[i]].clear();
    }
  }
  return 0;
}