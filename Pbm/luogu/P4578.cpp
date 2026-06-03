//2026/6/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[2005];
int head[2005], ecnt;

void addedge (int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

bool spfa(int n) {
  vector<int> d(n+1), vis(n+1, 1), cnt(n+1);
  queue<int> q;
  for(int i = 1; i <= n; ++i) q.push(i);
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d[v] > d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n) return 0;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return 1;
}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  fill(head+1, head+n+m+1, 0);
  ecnt = 0;
  for(int i = 1; i <= k; ++i) {
    int x, y, c; cin >> x >> y >> c;
    addedge(y+n, x, c);
    addedge(x, y+n, -c);
  }
  if(spfa(n+m)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}