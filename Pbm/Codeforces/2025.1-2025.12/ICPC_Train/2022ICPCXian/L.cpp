//2025/11/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, next; } e[2000005];
int head[1000005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

int dep[1000005], cnt_d[1000005];

void dfs(int u, int fa) {
  dep[u] = 1;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa) {
      dfs(v, u);
      dep[u] = max(dep[u],dep[v]+1);
    }
  }
}

void solve() {
  int n; cin >> n;
  cnt = 0;
  for(int i = 0; i <= n; ++i) head[i] = cnt_d[i] = 0;
  for(int i = 2; i <= n; ++i) {
    int v; cin >> v;
    addedge(i, v);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; ++i) ++cnt_d[dep[i]];
  int ans = 1e9;
  for(int i = 1; i <= n; ++i) {
    ans = min(ans, cnt_d[i]+i-1);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}