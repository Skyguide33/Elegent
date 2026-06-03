//2026/5/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, w, nxt; } e[40005];
int head[1005], ecnt;

void addedge(int u, int v, int w) {
  e[++ecnt] = {v, w, head[u]};
  head[u] = ecnt;
}

int spfa(int n) {
  vector<ll> d(n+1, LONG_LONG_MAX>>1), vis(n+1, 1), cnt(n+1);
  queue<int> q;
  for(int i = 1; i <= n; ++i) q.push(i);
  d[1] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    // cout << "u=" << u << endl;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].v, w = e[i].w;
      if(d[v] > d[u]+w) {
        d[v] = d[u]+w;
        // cout << "v=" << v << ' ' << d[v] << endl;
        cnt[v] = cnt[u]+1;
        if(cnt[v] >= n) return -1;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
  if(d[n] == LONG_LONG_MAX>>1) return -2;
  return d[n];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, ml, md; cin >> n >> ml >> md;
  for(int i = 1; i <= ml; ++i) {
    int a, b, d; cin >> a >> b >> d;
    addedge(a, b, d);
  }
  for(int i = 1; i <= md; ++i) {
    int a, b, d; cin >> a >> b >> d;
    addedge(b, a, -d);
  }
  for(int i = 2; i <= n; ++i) addedge(i, i-1, 0);
  cout << spfa(n) << endl;
  return 0;
}