//2026/5/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[150005];
int head[50005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int spfa(int n) {
  vector<int> d(n+1, INT_MIN>>1), vis(n+1), cnt(n+1);
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  d[0] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    // cout << "u=" << u << endl;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      // cout << "v=" << v << endl;
      if(d[v] < d[u]+w) {
        d[v] = d[u]+w;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n) return 0;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  return d[n];
}

void solve() {
  int n; cin >> n;
  int maxb = 0;
  for(int i = 1; i <= n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    addedge(a, b+1, c);
    maxb = max(maxb, b+1);
  }
  for(int i = 1; i <= maxb; ++i) {
    addedge(i-1, i, 0);
    addedge(i, i-1, -1);
  }
  cout << spfa(maxb) << endl;
  for(int i = 0; i <= maxb; ++i) head[i] = 0;
  ecnt = 0;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}