//2025/11/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

// 最大生成树裁剪非最大载重路径
struct Node1 { int u, v, w; } ed[50005];
bool cmp(const Node1 &a, const Node1 &b) { return a.w > b.w; }

struct Node2 { int to, w, next; } e[20005];
int head[10005], cnt; 

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, w, head[v]};
  head[v] = cnt;
}

// 并查集判断连通性
int s[10005];
int find_set(int x) { return (x == s[x]? x: s[x] = find_set(s[x])); }

int fa[10005][15], dep[10005], wl[10005], vis[10005];

void dfs(int u) {
  for(int i = 1; (1<<i) <= dep[u]; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(!vis[v]) {
      fa[v][0] = u;
      dep[v] = dep[u]+1;
      wl[v] = e[i].w;
      vis[v] = 1;
      dfs(v);
    }
  }
}

int LCA(int x, int y) {
  if(dep[x] < dep[y]) swap(x, y);
  for(int i = 14; i >= 0; --i) {
    if(dep[x]-(1<<i) >= dep[y]) x = fa[x][i];
  }
  if(x == y) return x;
  for(int i = 14; i >= 0; --i) {
    if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) cin >> ed[i].u >> ed[i].v >> ed[i].w;
  sort(ed+1, ed+m+1, cmp);
  for(int i = 1; i <= n; ++i) s[i] = i;
  for(int i = 1; i <= m; ++i) {
    int x = find_set(ed[i].u), y = find_set(ed[i].v);
    if(x == y) continue;
    s[x] = y;
    addedge(ed[i].u, ed[i].v, ed[i].w);
  }
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      vis[i] = 1;
      dfs(i);
    }
  }
  int q; cin >> q;
  while(q--) {
    int x, y; cin >> x >> y;
    if(find_set(x) != find_set(y)) {
      cout << -1 << endl;
      continue;
    }
    int lca = LCA(x, y);
    int maxw = 1e9;
    while(x != lca) {
      maxw = min(maxw, wl[x]);
      x = fa[x][0];
    }
    while(y != lca) {
      maxw = min(maxw, wl[y]);
      y = fa[y][0];
    }
    cout << maxw << endl;
  }
  return 0;
}