//2025/2/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge { int to, nxt; } e[20005];
int head[10005], cnt, n, w[10005];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

ll dfs(int u, int fa, int dep) {
  int res = dep*w[u];
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v != fa)  res += dfs(v, u, dep+1);
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int u, v; cin >> w[i] >> u >> v;
    if(u) addedge(i, u);
    if(v) addedge(i, v);
  }
  ll ans = LONG_LONG_MAX>>1;
  for(int i = 1; i <= n; ++i)  ans = min(ans, dfs(i, 0, 0));
  cout << ans << endl;
  return 0;
}