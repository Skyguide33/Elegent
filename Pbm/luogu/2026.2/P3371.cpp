//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, w, nxt; } e[500005];
int head[10005], cnt;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
}

int n, d[10005];

bool spfa(int src) {
  fill(d+1, d+n+1, INT_MAX);
  d[src] = 0;
  vector<int> vis(n+1, 0), cnt(n+1, 0);
  queue<int> q;
  q.push(src);
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to, w = e[i].w;
      if(d[v] > d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n) return 1; // 若有负环, 返回1
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return 0; // 无负环, 返回0
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, s; cin >> n >> m >> s;
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  spfa(s);
  for(int i = 1; i <= n; ++i) cout << d[i] << ' ';
  cout << endl;
  return 0;
}