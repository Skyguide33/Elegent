//2026/3/2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[400005];
int head[5005], cnt;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, d[5005], vis[5005];

int prim(int s=1) {
  const static int inf = INT_MAX>>1;
  fill(d, d+n+1, inf);
  d[s] = 0;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    int u = 0;
    for(int j = 1; j <= n; ++j) 
      if(!vis[j] && d[j] < d[u]) u = j;
    if(d[u] == inf) return -1;
    vis[u] = 1;
    ans += d[u]; 
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(!vis[v] && w < d[v]) d[v] = w;
    }
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w); addedge(v, u, w);
  }
  int ans = prim();
  if(ans == -1) cout << "orz" << endl;
  else cout << ans << endl;
  return 0;
}