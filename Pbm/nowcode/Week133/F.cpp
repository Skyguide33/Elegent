//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

ll inv(ll num) {
  ll b = num, p = MOD-2;
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

struct Edge { int to, nxt; } e[400005];
int head[200005], cnt, n;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]}; 
  head[v] = cnt;
}

int d1[200005], d2[200005], up[200005], vis[200005], cnt1, cnt2;

void dfs_d(int u, int fa) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v == fa) continue;
    dfs_d(v, u);
    int len = d1[v]+1;
    if(len > d1[u]) d2[u] = d1[u], d1[u] = len;
    else if(len > d2[u]) d2[u] = len;
  }
}

void dfs_u(int u, int fa) {
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(v == fa) continue;
    if(d1[u] == d1[v]+1) up[v] = max(up[u], d2[u])+1;
    else up[v] = max(up[u], d1[u])+1;
    dfs_u(v, u);
  }
}

void dfs(int u) {
  vis[u] = 1;
  ++cnt1;
  if(max(d1[u], up[u]) == 1) ++cnt2;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if(vis[v] == 1) continue;
    dfs(v);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs_d(1, 0);
  dfs_u(1, 0);
  ll ans = 1;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      cnt1 = cnt2 = 0;
      dfs(i);
      ans *= cnt2*inv(cnt1);
      // cout << cnt2 << ' ' << cnt1 << endl;
    }
  }
  cout << 0 << endl;
  return 0;
}