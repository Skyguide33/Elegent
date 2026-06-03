//2025/11/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 6005

int w[N];

struct Edge { int to, next; } e[N];
int head[N], cnt, dp[N][2], ind[N];

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

void dfs(int u) {
  dp[u][1] = w[u];
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    dfs(v);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> w[i];
  for(int i = 1; i < n; ++i) {
    int l, k; cin >> l >> k;
    ++ind[l];
    addedge(k, l);
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(!ind[i]) {
      dfs(i);
      ans += max(dp[i][0], dp[i][1]);
    }
  }
  cout << ans << endl;
  return 0;
}