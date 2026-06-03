//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt;} e[1000005];
int head[300005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

using PLI = pair<ll, int>;

priority_queue<ll> vt[300005];
ll ulk[300005], a[300005], vis[300005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  fill(ulk+1, ulk+n+1, LONG_LONG_MAX>>1);
  priority_queue<PLI, vector<PLI>, greater<PLI>> q;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] == 0) q.push({0, i});
  }
  for(int i = 1; i <= k; ++i) {
    int t, sc; cin >> t >> sc;
    for(int j = 1; j <= sc; ++j) {
      int v; cin >> v;
      q.push({t, v});
    }
  }
  for(int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w); 
  }
  while(!q.empty()) {
    auto [t, u] = q.top(); q.pop();
    // cout << u << ' ' << t << endl;
    if(t >= ulk[u]) continue;
    ulk[u] = t;
    for(int i = head[u]; i; i = e[i].nxt) {
      auto [v, w, _] = e[i];
      if(ulk[v] != LONG_LONG_MAX>>1) continue;
      vt[v].push(t+w);
      if((int)vt[v].size() == a[v]) {
        q.push({vt[v].top(), v});
        vt[v].pop();
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(ulk[i] == LONG_LONG_MAX>>1) cout << -1 << ' ';
    else cout << ulk[i] << ' ';
  }
  cout << endl;
  return 0;
}