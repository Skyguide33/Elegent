//2025/9/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge{ int w, nxt; } e[1000005];
int head[500005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int fa[500005][20], dep[500005];

void dfs(int u, int father) {
  dep[u] = dep[father]+1;
  fa[u][0] = father;
  for(int i = 1; (1<<i) <= dep[u]; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
  for(int i = head[u]; i; i = e[i].nxt) 
    if(e[i].w != father) dfs(e[i].w, u);
}

int LCA(int x, int y) {
  if(dep[x] < dep[y]) swap(x, y);
  for(int i = 19; i >= 0; --i) 
    if(dep[x]-(1<<i) >= dep[y]) x = fa[x][i];
  if(x == y) return x;
  for(int i = 19; i >= 0; --i) 
    if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, rt; cin >> n >> m >> rt;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  dfs(rt, 0); // 预处理父亲节点
  while(m--) {
    int a, b; cin >> a >> b;
    cout << LCA(a, b) << endl;
  }
}