//2026/3/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, w, nxt; } e[200005];
int head[100005], cnt;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, d[100005];

void dijkstra(int src) {
  fill(d+1, d+n+1, INT_MAX>>1);
  priority_queue<pair<int, int>> q;
  vector<int> vis(n+1, 0);
  d[src] = 0; q.push({0, src});
  while(!q.empty()) {
    int u = q.top().second; q.pop();
    if(vis[u]) continue; 
    vis[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if(vis[v]) continue;
      int dis = d[u]+w;
      if(d[v] > dis) {
        d[v] = dis;
        q.push({-dis, v});
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, s; cin >> n >> m >> s;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  dijkstra(s);
  for(int i = 1; i <= n; ++i) cout << d[i] << ' ';
  cout << endl;
  return 0;
}