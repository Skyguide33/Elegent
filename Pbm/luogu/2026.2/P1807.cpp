//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, w, nxt; } e[50005];
int head[1505], cnt;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, m;
ll d[1505];

bool spfa(int src) {
  fill(d+1, d+n+1, INT_MIN>>1);
  vector<int> vis(n+1, 0), cnt(n+1, 0);
  d[src] = 0;
  queue<int> q;
  q.push(src);
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if(d[v] < d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n) return 1;
        if(!vis[v]) q.push(v);
      }
    }
  }
  return 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  spfa(1);
  if(d[n] == INT_MIN>>1) cout << -1 << endl;
  else cout << d[n] << endl;
  return 0;
}

