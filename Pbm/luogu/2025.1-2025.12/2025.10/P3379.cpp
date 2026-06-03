//2025/10/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005

struct edge { int to, next; } e[N<<1];
int head[N], son[N], deep[N], siz[N], fa[N], top[N], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

void dfs1(int u) {
  siz[u] = 1;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa[u]) {
      deep[v] = deep[u]+1;
      fa[v] = u;
      dfs1(v);
      siz[u] += siz[v];
      if(!son[u] || siz[son[u]] < siz[v]) son[u] = v;
    }
  }
}

void dfs2(int u, int topu) {
  top[u] = topu;
  if(!son[u]) return;
  dfs2(son[u], topu);
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa[u] && v != son[u]) dfs2(v, v);
  }
}

int LCA(int x, int y) {
  while(top[x] != top[y]) {
    if(deep[top[x]] < deep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return (deep[x] > deep[y]? y: x);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, s; cin >> n >> m >> s;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs1(s);
  dfs2(s, s);
  while(m--) {
    int x, y; cin >> x >> y;
    cout << LCA(x, y) << endl;
  }
  return 0;
}