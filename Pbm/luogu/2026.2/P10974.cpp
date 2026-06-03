//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, w, nxt; } e[400005];
int head[200005], cnt, n;

void init() { // 多测情况下必须进行初始化
  cnt = 0;
  fill(head+1, head+n+1, 0);
}

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, w, head[v]}; // 若为有向边则删去下两行
  head[v] = cnt;
}

int d[200005], f[200005], ans;

void dfs_d(int u, int fa) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if(v == fa) continue;
    dfs_d(v, u);
    if(e[head[v]].nxt) d[u] += min(w, d[v]);
    else d[u] += w;
  }
}

void dfs_f(int u, int fa) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to, w = e[i].w;
    if(v == fa) continue;
    if(!e[head[u]].nxt) f[v] = d[v]+w;
    else f[v] = d[v]+min(w, f[u]-min(w, d[v])); 
    dfs_f(v, u);
  }
  ans = max(ans, f[u]);
}

void solve() {
  cin >> n;
  init();
  fill(d+1, d+n+1, 0);
  ans = 0;
  for(int i = 1; i < n; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  dfs_d(1, 0);
  f[1] = d[1];
  dfs_f(1, 0);
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}