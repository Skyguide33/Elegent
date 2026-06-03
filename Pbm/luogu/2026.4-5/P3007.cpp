//2026/5/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt; } e[8005];
int head[2005], ecnt;

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

int vis[2005], n;

void dfs(int u) {
  vis[u] = 1;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(!vis[v]) dfs(v);
  }
}

bool check(int src, int des) {
  fill(vis+1, vis+2*n+1, 0);
  dfs(src);
  return vis[des];
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int b, c; char vb, vc; cin >> b >> vb >> c >> vc;
    addedge(b+(vb=='N')*n, c+(vc=='Y')*n);
    addedge(c+(vc=='N')*n, b+(vb=='Y')*n);
  }

  bool flag = 1;
  string ans;
  for(int i = 1; i <= n; ++i) {
    bool x = check(i, i+n), y = check(i+n, i);
    if(x && y) {
      flag = 0;
      break;
    } else if(x) ans += 'Y';
    else if(y) ans += 'N';
    else ans += '?';
  }
  if(flag) cout << ans << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}