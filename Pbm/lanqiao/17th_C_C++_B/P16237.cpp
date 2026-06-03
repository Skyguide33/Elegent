//2026/3/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[200005];
int head[100005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int vis[100005];

int dfs(int u) {
  vis[u] = 1;
  int ucnt = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(vis[v]) continue;
    ucnt += dfs(v);
  }
  return ucnt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  int ucnt1 = 0, bcnt = 0;
  for(int i = 1; i <= n; ++i) {
    if(vis[i]) continue;
    if(dfs(i) == 1) ++ucnt1;
    ++bcnt;
  }
  cout << bcnt-1 << ' ';
  if(bcnt == 1) cout << 0 << endl;
  else if(bcnt == 2) cout << 1 << endl;
  else {
    if(ucnt1 > 2) cout << 2 << endl;
    else cout << 1 << endl;
  }
  return 0;
}