//2025/12/1 补题
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, next; } e[400005];
int head[200005], dge[200005], dep[200005], ans[200005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
  ++dge[u]; ++dge[v];
}

int dfs(int u, int fa) {
  dep[u] = dep[fa]+1;
  int mxdep = dep[u], cnt = 1;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v == fa || dge[v] == 1) continue;
    int n_dep = dfs(v, u);
    if(n_dep == mxdep) cnt += ans[v];
    else if(n_dep > mxdep) {
      mxdep = n_dep;
      cnt = ans[v];
    }
  }
  ans[u] = cnt;
  return mxdep;
}

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << endl;
}