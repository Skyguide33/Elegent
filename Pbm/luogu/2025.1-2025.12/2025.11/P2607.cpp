//2025/11/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

struct Edge { int to, next; } e[N];
int head[N], cnt;

int father[N], vis[N], w[N];
ll dp[N][2];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  father[v] = u;
}

int find_rt(int u) {
  while(!vis[u]) {
    vis[u] = 1;
    u = father[u];
  }
  return u;
}

void dfs(int u, int rt) {
  dp[u][1] = w[u];
  dp[u][0] = 0;
  vis[u] = 1;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v == rt) continue;
    dfs(v, rt);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}

ll solve(int u) {
  int rt = find_rt(u);
  dfs(rt, rt);
  ll res = dp[rt][0];
  rt = father[rt];
  dfs(rt, rt);
  res = max(res, dp[rt][0]);
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int v = 1; v <= n; ++v) {
    int u; cin >> w[v] >> u;
    addedge(u, v);
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) ans += solve(i);
  }
  cout << ans << endl;
  return 0;
}