//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, nxt; } e[2000005];
int head[1005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

int vis[1005];

bool dfs(int u, int c) {
  vis[u] = c;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(!vis[v]) {
      if(dfs(v, 3-c)) return 1;
    } else if(vis[v] == c) return 1;
  }
  return 0;
}

void solve(int Case) {
  cout << "case " << Case << ':' << endl;
  int n, m; cin >> n >> m;
  fill(head+1, head+n+1, 0);
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  fill(vis+1, vis+n+1, 0);
  bool flag = 0;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i] && dfs(i, 1)) {
      flag = 1;
      break;
    }
  }
  if(flag) cout << "No" << endl;
  else cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  for(int i = 1; i <= T; ++i) solve(i);
  return 0;
}