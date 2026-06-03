//2026/5/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005

struct Edge { int v, nxt; } e[N<<1];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int w[N];
int pre[N], post[N], id[N], x, idx;
ll up[N], down[N];
ll pfx[N], suf[N];

void dfs(int u, int fa) {
  id[++idx] = u;
  pre[u] = idx;
  up[u] = up[fa]+w[u];
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v, u);
    down[u] = max(down[u], down[v]);
  }
  down[u] += w[u]^x;
  post[u] = idx;
}

void solve() {
  int n; cin >> n >> x;
  for(int i = 1; i <= n; ++i) cin >> w[i];
  ecnt = 0;
  for(int i = 1; i <= n; ++i) head[i] = down[i] = 0;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  idx = 0;
  dfs(1, 0);
  for(int i = 1; i <= n; ++i) pfx[i] = max(pfx[i-1], up[id[i]]);
  suf[n+1] = 0;
  for(int i = n; i >= 1; --i) suf[i] = max(suf[i+1], up[id[i]]);
  ll ans = 1e18;
  for(int i = 1; i <= n; ++i) {
    ans = min(ans, max({pfx[pre[i]-1], suf[post[i]+1], up[i]+down[i]-w[i]}));
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}