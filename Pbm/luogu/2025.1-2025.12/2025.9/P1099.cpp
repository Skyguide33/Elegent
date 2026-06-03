//2025/9/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edge { int v, w; };

vector<edge> e[305];

int f[305], dep[305], dia[305], pres[305], vis[305], c, cnt;

void dfs(int u, int fa) {
  f[u] = fa;
  for(auto& ed: e[u]) {
    if(ed.v == fa || vis[ed.v]) continue;
    dep[ed.v] = dep[u]+ed.w;
    if(dep[ed.v] > dep[c]) c = ed.v;
    dfs(ed.v, u);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, s; cin >> n >> s;
  for(int i = 1; i < n; ++i) {
    int u, v, w; cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  // 获取直径信息
  dfs(1, 0);
  dep[c] = 0;
  dfs(c, 0);
  for(int u = c; u; u = f[u]) {
    dia[++cnt] = u;
    pres[cnt] = dep[u];
    vis[u] = 1;
  }
  int maxd = 0;
  for(int i = 1; i <= cnt; ++i) {
    c = dia[i]; dep[c] = 0; 
    dfs(c, 0);
    maxd = max(maxd, dep[c]);
  }
  // cout << maxd << endl;
  int l = cnt, r = cnt, ans = 1<<30; 
  pres[0] = 1<<30;
  for(; r >= 1; --r) {
    while(l >= 1 && pres[l-1]-pres[r] <= s) --l;
    ans = min(max(maxd, max(pres[1]-pres[l], pres[r])), ans);
  }
  cout << ans << endl;
  return 0;
}