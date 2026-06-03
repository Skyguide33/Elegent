//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int v, nxt;} e[200005];
int head[100005], ecnt, cut[200005];

void init(int n) {
  fill(head+1, head+n+1, 0);
  fill(cut+2, cut+2*n, 0);
  ecnt = 1;
}

void addedge(int u, int v) {
  e[++ecnt] = {v, head[u]};
  head[u] = ecnt;
}

pair<int, int> q[100005];
int a[100005], tl, ans, flag;

void dfs1(int u, int fa) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v != fa) {
      if(a[v]*2 < a[u]) {
        q[++tl] = {u, v};
        cut[i] = 1;
      } else if(a[u]*2 < a[v]) {
        q[++tl] = {v, u};
        cut[i^1] = 1;
      }
      dfs1(v, u);
    }
  }
}

void dfs2(int u, int fa) {
  --ans;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v == fa || cut[i^1]) continue;
    if(cut[i]) {
      flag = 1;
      return;
    }
    dfs2(v, u);
    if(flag) return;
  }
}

void solve() {
  int n; cin >> n;
  init(n);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v); addedge(v, u);
  }
  tl = 0; 
  dfs1(1, 0);
  ans = n;
  flag = 0;
  for(int i = 1; i <= tl; ++i) {
    dfs2(q[i].first, q[i].second);
    if(flag) break;
  }
  if(flag) cout << 0 << endl;
  else cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}