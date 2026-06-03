//2026/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[2005];
int head[101], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

bool spfa(int n) {
  vector<int> d(n+1), vis(n+1, 1), cnt(n+1);
  queue<int> q;
  for(int i = 0; i <= n; ++i) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d[v] < d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n+1) return 0;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return 1;
}

void solve() {
  int n, m; cin >> n >> m;
  fill(head, head+n+1, 0);
  ecnt = 0;
  for(int i = 1; i <= m; ++i) {
    int s, t, v; cin >> s >> t >> v;
    addedge(s-1, t, v);
    addedge(t, s-1, -v);
  }
  if(spfa(n)) cout << "true" << endl;
  else cout << "false" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}