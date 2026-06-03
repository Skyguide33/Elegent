//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[400005];
int head[200005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int w[200005], maxn;

void dfs(int u, int fa) {
  
}

void solve() {
  int n, k; cin >> n >> k;
  fill(head+1, head+n+1, 0);
  ecnt = 0;
  for(int i = 1; i <= n; ++i) cin >> w[i];
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  dfs(1, 0);

}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}