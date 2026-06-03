//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 100005;

struct Edge { int to, next; } e[N<<1];
int head[N], cnt, fa[N][18], deep[N], d[N];

void init(int n) {
  for(int i = 1; i <= n; ++i) head[i] = -1;
  n <<= 1;
  for(int i = 0; i < n; ++i) e[i].next = -1;
  cnt = 0;
}

void addedge(int u, int v) {
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt++;
}

void dfs1(int u, int father) {
  deep[u] = deep[father]+1;
  fa[u][0] = father;
  for(int i = 1; (1<<i) <= deep[u]; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
  for(int i = head[u]; ~i; i = e[i].next)
    if(e[i].to != father) dfs1(e[i].to, u);
}

int LCA(int x, int y) {
  if(deep[x] < deep[y]) swap(x, y);
  for(int i = 17; i >= 0; --i)
    if(deep[x]-(1<<i) >= deep[y]) x = fa[x][i];
  if(x == y) return x;
  for(int i = 17; i >= 0; --i) 
    if(fa[x][i] != fa[y][i]) {
      x = fa[x][i]; y = fa[y][i];
    }
  return fa[x][0];
}

void dfs2(int u, int father) {
  for(int i = head[u]; ~i; i = e[i].next)
    if(e[i].to != father) {
      dfs2(e[i].to, u);
      d[u] += d[e[i].to];
    }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  init(n);
  for(int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    addedge(x, y); addedge(y, x);
  }
  dfs1(1, 0);
  while(k--) {
    int s, t; cin >> s >> t;
    int lca = LCA(s, t);
    ++d[s]; ++d[t]; --d[lca]; --d[fa[lca][0]];
  }
  dfs2(1, 0);
  int ans = 0;
  for(int i = 1; i <= n; ++i) ans = max(ans, d[i]);
  cout << ans << endl;
  return 0;
}