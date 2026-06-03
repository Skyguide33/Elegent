//2025/10/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 20005

struct edge { int to, w, next; } e[N<<1];
int head[N];
int siz[N], dep[N], dis[N], sub_rt[N], vis[N], md3, sum[3], cnt, root, sub_n, max_siz, p;

void addedge(int u, int v, int w) {
  e[++cnt] = {v, w, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, w, head[v]};
  head[v] = cnt;
} 

void dfs_root(int u, int fa) {
  siz[u] = 1;
  int temp = 0;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa && !vis[v]) {
      dfs_root(v, u);
      temp = max(temp, siz[v]);
      siz[u] += siz[v];
    }
  }
  temp = max(temp, sub_n-siz[u]);
  if(temp < max_siz) {
    root = u;
    max_siz = temp;
  }
}

void dfs_dep(int u, int fa, int from) {
  sub_rt[u] = from; dis[++p] = u;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to, w = e[i].w;
    if(v != fa && !vis[v]) {
      dep[v] = dep[u]+w;
      dfs_dep(v, u, from);
    } 
  }
}

void dfs_dis(int u) {
  dep[u] = 0; sub_rt[u] = u;
  p = 0; dis[++p] = u;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to, w = e[i].w;
    if(!vis[v]) {
      dep[v] = w;
      dfs_dep(v, u, v);
    } 
  }
  sum[0] = sum[1] = sum[2] = 0;
  map<int, vector<int>> md;
  for(int i = 1; i <= p; ++i) {
    int num = dep[dis[i]]%3, num2 = (3-num)%3;
    int rt = sub_rt[dis[i]];
    if(!md.count(rt)) md[rt] = {0, 0, 0};
    md3 += sum[num2]-md[rt][num2];
    ++md[rt][num]; ++sum[num];
  }
}

void dfs_ans(int u, int fa) {
  vis[u] = 1;
  dfs_dis(u);
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa && !vis[v]) {
      max_siz = N; root = 0; sub_n = siz[v];
      dfs_root(v, 0);
      dfs_ans(root, 0);
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v, w; cin >> u >> v >> w;
    addedge(u, v, w);
  }
  max_siz = N; root = 0; sub_n = n;
  dfs_root(1, 0);
  dfs_ans(root, 0);
  md3 = md3*2+n;
  int all = n*n;
  int gd = gcd(md3, all);
  cout << md3/gd << '/' << all/gd << endl;
  return 0;
}