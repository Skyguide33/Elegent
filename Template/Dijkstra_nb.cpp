//2025/4/22  邻接表版本
#include <bits/stdc++.h>
using namespace std;

struct Edge { int to, w, nxt; } e[400005];
int head[100005], cnt;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, d[100005], pre[100005];

void dijkstra(int s) {
  fill(d+1, d+n+1, INT_MAX>>1);
  fill(pre+1, pre+n+1, 0);
  priority_queue<pair<int, int>> q;
  vector<int> final(n+1, 0);
  d[s] = 0; q.push({0, s});
  while(!q.empty()) {
    int u = q.top().second; q.pop();
    if(final[u]) continue;
    final[u] = 1;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if(final[v]) continue;
      int dis = d[u]+w;
      if(d[v] > dis) {
        d[v] = dis;
        pre[v] = u;
        q.push({-dis, v});
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, s; cin >> n >> m >> s;
  while(m--) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  dijkstra(s);
  for(int i = 1; i <= n; ++i) cout << d[i] << ' ';
  cout << endl;
  return 0;
}