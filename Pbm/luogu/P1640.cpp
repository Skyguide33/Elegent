//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[2000005];
int head[10005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int vis[1000005], match[1000005], idx;

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

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int u1, u2; cin >> u1 >> u2;
    addedge(u1, i); addedge(u2, i);
  }
  int ans = 1;
  while(ans <= 10000) {
    idx = ans;
    if(!dfs(ans)) break;
    ++ans;
  }
  cout << ans-1 << endl;
  return 0;
}