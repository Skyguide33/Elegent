//2026/1/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

struct Edge { int to, next; } e[400005];
int head[200005], cnt, n, son[200005], dep[200005];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

void dfs(int u, int fa) {
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa) {
      dep[v] = dep[u]+1;
      ++son[u];
      dfs(v, u);
      son[u] += son[v];
    }
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; ++i) head[i] = son[i] = dep[i] = 0;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs(1, 0);
  ll ans = 0;
  for(int i = 2; i <= n; ++i) {
    ans = (ans+(1ll*(son[i]+1)*(n-son[i]-1-dep[i])))%MOD;
  }
  for(int i = 1; i <= n; ++i) ans = (ans+son[i])%MOD;
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}