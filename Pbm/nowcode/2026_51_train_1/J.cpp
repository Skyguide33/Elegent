//2026/5/1 补题
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[1000005];
int head[1000005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dg[1000005], ans[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); ++dg[v];
  }
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(dg[i] == 0) q.push(i);
  }
  int len = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    ans[++len] = u;
    for(int i = head[u]; i; i = e[i].nxt) {
      if(--dg[e[i].v] == 0) q.push(e[i].v);
    }
  }
  if(len < n) {
    cout << 2 << endl;
    for(int i = 1; i <= n; ++i) cout << i << ' ';
    cout << endl;
    for(int i = 1; i <= n; ++i) cout << n-i+1 << ' ';
    cout << endl;
  } else {
    cout << 1 << endl;
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}