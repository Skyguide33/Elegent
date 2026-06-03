//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], dist[200005], maxdist[200005];

struct Node { int to, nxt; } e[400005];
int head[200005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

void dijkstra() {
  priority_queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int u = q.top(); q.pop();
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if(dist[v] > dist[u]+1) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 2; i <= n; ++i) dist[i] = 1e9;
  while(m--) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dijkstra();
  for(int i = 1; i <= n; ++i) {
    maxdist[a[i]] = max(maxdist[a[i]], dist[i]);
  }
  for(int i = 1; i <= k; ++i) {
    cout << maxdist[i] << ' ';
  }
  cout << endl;
  return 0;
}