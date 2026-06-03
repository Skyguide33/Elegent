//2025/2/21
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, w, nxt; } e[6005];
int head[2005], cnt;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, d[2005];

bool bellman_ford(int src) {
  fill(d+1, d+n+1, INT_MAX>>1);
  d[src] = 0;
  for(int i = 1; i <= n; ++i) {
    bool flag = 0;
    for(int j = 1; j <= n; ++j) {
      if(d[j] == INT_MAX>>1) continue;
      for(int k = head[j]; k; k = e[k].nxt) {
        int v = e[k].to, w = e[k].w;
        if(d[v] > d[j]+w) {
          flag = 1;
          d[v] = d[j]+w;
        }
      }
    }
    if(!flag) return 0;
  }
  return 1;
}

void solve() {
  int m; cin >> n >> m;
  cnt = 0;
  for(int i = 1; i <= n; ++i) head[i] = 0;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
    if(w >= 0) addedge(v, u, w);
  }
  if(bellman_ford(1)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}