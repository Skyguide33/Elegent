//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Edge { int to, nxt; } e[200005];
int head[100005], cnt;

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]}; // 若为有向边则删去下两行
  head[v] = cnt;
}

int n, d1[100005], d2[100005], up[100005], ans[100005], tail;

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

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs_d(1, 0);
  dfs_u(1, 0);
  int maxlen = INT_MAX>>1;
  for(int i = 1; i <= n; ++i) {
    int len = max(d1[i], up[i]);
    if(len < maxlen) {
      maxlen = len;
      ans[tail=1] = i;
    } else if(len == maxlen) ans[++tail] = i;
  }
  for(int i = 1; i <= tail; ++i) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}