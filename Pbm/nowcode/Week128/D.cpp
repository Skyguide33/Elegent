//2026/1/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, nxt; } e[400005];
int head[200005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

int son[200005], father[200005];

void dfs(int u, int fa) {
  father[u] = fa;
  son[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v != fa) {
      dfs(v, u);
      son[u] += son[v];
    }
  }
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) head[i] = son[i] = 0;
  cnt = 0;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs(1, 0); 
  int ans = 0;
  for(int u = 1; u <= n; ++u) {
    if((n-son[u])%2 == 0 && u != 1) continue;
    bool flag = 1;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if(v == father[u]) continue;
      if(son[v]%2 == 0) {
        flag = 0;
        break;
      }
    }
    ans += flag;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}