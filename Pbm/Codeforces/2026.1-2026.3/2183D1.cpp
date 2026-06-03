//2026/3/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[400005];
int head[200005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int dep[200005], fanum[200005], cnt[200005];

void dfs(int u, int fa) {
  dep[u] = dep[fa]+1;
  ++cnt[dep[u]];
  bool flag = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v != fa) {
      dfs(v, u);
      flag = 0;
    }
  }
  if(!flag) ++fanum[dep[u]+1];
}

void solve() {
  int n; cin >> n;
  ecnt = 0;
  fill(head+1, head+n+1, 0);
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  fill(fanum+1, fanum+n+1, 0);
  fill(cnt+1, cnt+n+1, 0);
  dfs(1, 0);
  int ans = 1;
  for(int i = 2; cnt[i]; ++i) {
    ans = max(ans, cnt[i]+(fanum[i] == 1));
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}