//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[40005];
int head[401], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int vis[405], match[405], idx;

bool dfs(int u) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(vis[v] == idx) continue;
    vis[v] = idx;
    if(!match[v] || dfs(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

void solve() {
  int n; cin >> n;
  fill(head+1, head+n+1, 0);
  ecnt = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      int v; cin >> v;
      if(v) addedge(i, j+n);
    }
  }
  int res = 0;
  fill(vis+n+1, vis+2*n+1, 0);
  fill(match+n+1, match+2*n+1, 0);
  for(int i = 1; i <= n; ++i) {
    idx = i;
    res += dfs(i);
  }
  if(res < n) cout << "No" << endl;
  else cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}