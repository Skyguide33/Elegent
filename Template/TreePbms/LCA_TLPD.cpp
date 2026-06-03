//2026/3/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge{ int v, nxt; } e[1000005];
int head[500005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int sz[500005], dep[500005], son[500005], fa[500005], top[500005];

void dfs1(int u, int father) {
  fa[u] = father; sz[u] = 1; dep[u] = dep[father]+1; 
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v == father) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if(sz[v] > sz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  top[u] = t;
  if(!son[u]) return;
  dfs2(son[u], t);
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v != fa[u] && v != son[u]) dfs2(v, v);
  }
}

int LCA(int x, int y) {
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y]? x: y;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, s; cin >> n >> m >> s;
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    addedge(x, y); addedge(y, x);
  }
  dfs1(s, 0);
  dfs2(s, s);
  while(m--) {
    int a, b; cin >> a >> b;
    cout << LCA(a, b) << endl;
  }
  return 0;
}