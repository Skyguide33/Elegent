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
int cut[N];
vector<int> dcc[N];
int cnt, root;

void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk[++top] = u;
  bool flag = 1;
  int child = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v != u) flag = 0;
    if(!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
      if(low[v] >= dfn[u]) {
        ++child;
        if(child > 1 || u != root) cut[u] = 1;
        int z; ++cnt;
        do {
          z = stk[top--];
          dcc[cnt].push_back(z);
        } while(z != v);
        dcc[cnt].push_back(u);
      }
    } else low[u] = min(low[u], dfn[v]);
  }
  if(flag) dcc[++cnt].push_back(u);
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
    if(!dfn[i]) tarjan(i);
  cout << cnt << endl;
  for(int i = 1; i <= cnt; ++i) {
    cout << dcc[i].size() << ' ';
    for(int x: dcc[i]) cout << x << ' ';
    cout << endl;
  }
  return 0;
}