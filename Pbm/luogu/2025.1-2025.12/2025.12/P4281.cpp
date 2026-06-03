//2025/12/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005

struct Edge { int to, nxt; } e[N<<1];
int head[N], cnt;
int dep[N], fa[N][20];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

void dfs(int u) {
  for(int i = 1; (1<<i) <= dep[u]; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v == fa[u][0]) continue;
    dep[v] = dep[u]+1;
    fa[v][0] = u;
    dfs(v);
  }
}

int LCA(int x, int y) {
  if(dep[x] < dep[y]) swap(x, y);
  for(int i = 18; i >= 0; --i){
    if(dep[x]-(1<<i) >= dep[y]) x = fa[x][i]; 
  }
  if(x == y) return x;
  for(int i = 18; i >= 0; --i) {
    if(fa[x][i] != fa[y][i]) {
      x = fa[x][i]; y = fa[y][i];
    }
  }
  return fa[x][0];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs(1);
  while(m--) {
    int a, b, c; cin >> a >> b >> c;
    int lca1 = LCA(a, b), lca2 = LCA(a, c), lca3 = LCA(b, c);
    int ans1 = lca1;
    if(dep[lca2] > dep[ans1]) ans1 = lca2;
    if(dep[lca3] > dep[ans1]) ans1 = lca3;
    int ans2 = dep[a]+dep[b]+dep[c]-dep[lca1]-dep[lca2]-dep[lca3];
    cout << ans1 << ' ' << ans2 << endl;
  }
  return 0;
}