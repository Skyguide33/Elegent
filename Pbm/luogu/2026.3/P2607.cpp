//2026/3/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 1000005

struct Edge { int v, nxt; } e[N];
int head[N], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int w[N], vis[N], r1, r2;
ll dp[N][2];

void find_rt(int u, int rt) {
  vis[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v == rt) {
      r1 = u, r2 = v;
      return;
    } else if(!vis[v]) find_rt(v, rt);
  }
}

ll dfs(int u, int rt) {
  vis[u] = 1;
  dp[u][0] = 0, dp[u][1] = w[u];
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v == rt) continue;
    dfs(v, rt);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
  return dp[u][0];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int v; cin >> w[i] >> v;
    addedge(v, i); 
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(vis[i]) continue;
    r1 = 0, r2 = 0;
    find_rt(i, i);
    if(r1) ans += max(dfs(r1, r1), dfs(r2, r2));
  }
  cout << ans << endl;
  return 0;
}