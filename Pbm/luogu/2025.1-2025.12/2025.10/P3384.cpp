//2025/10/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define N 100005
#define ls p<<1
#define rs p<<1|1

struct edge { int to, next; } e[N<<1];
int head[N], dep[N], siz[N], son[N], fa[N], top[N], cnt, seq;
int id[N], pos[N], init_v[N], tree[N<<2], tag[N<<2];
int n, m, r, MOD; 

void push_up(int p) {
  tree[p] = (tree[ls]+tree[rs])%MOD;
}

void build(int p, int pl, int pr) {
  tag[p] = 0;
  if(pl == pr) {
    tree[p] = init_v[pos[pl]]%MOD;
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls, pl, mid);
  build(rs, mid+1, pr);
  push_up(p);
}

void addtag(int p, int pl, int pr, int d) {
  tag[p] = (tag[p]+d)%MOD;
  tree[p] = (tree[p]+1ll*(pr-pl+1)*d)%MOD;
}

void push_down(int p, int pl, int pr) {
  if(tag[p]) {
    int mid = (pl+pr)>>1;
    addtag(ls, pl, mid, tag[p]);
    addtag(rs, mid+1, pr, tag[p]);
    tag[p] = 0;
  }
}

void update(int L, int R, int p, int pl, int pr, int d) {
  if(L <= pl && pr <= R) return addtag(p, pl, pr, d);
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls, pl, mid, d);
  if(R > mid) update(L, R, rs, mid+1, pr, d);
  push_up(p);
} 

int query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return tree[p];
  push_down(p, pl, pr);
  int res = 0, mid = (pl+pr)>>1;
  if(L <= mid) res += query(L, R, ls, pl, mid);
  if(R > mid) res += query(L, R, rs, mid+1, pr);
  return res%MOD;
}

void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
  e[++cnt] = {u, head[v]};
  head[v] = cnt;
}

void dfs1(int u) {
  siz[u] = 1;
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa[u]) {
      fa[v] = u;
      dep[v] = dep[u]+1;
      dfs1(v);
      siz[u] += siz[v];
      if(!son[u] || siz[son[u]] < siz[v]) son[u] = v;
    }
  }
}

void dfs2(int u, int topu) {
  top[u] = topu;
  id[u] = ++seq;
  pos[seq] = u;
  if(!son[u]) return;
  dfs2(son[u], topu);
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

void update_range(int x, int y, int z) {
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    update(id[top[x]], id[x], 1, 1, n, z);
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  update(id[x], id[y], 1, 1, n, z);
} 

int query_range(int x, int y) {
  int res = 0;
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    res = (res+query(id[top[x]], id[x], 1, 1, n))%MOD;
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  res = (res+query(id[x], id[y], 1, 1, n))%MOD;
  return res;
}

void update_tree(int x, int z) {
  update(id[x], id[x]+siz[x]-1, 1, 1, n, z);
}

int query_tree(int x) {
  return (query(id[x], id[x]+siz[x]-1, 1, 1, n))%MOD;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> r >> MOD;
  for(int i = 1; i <= n; ++i) cin >> init_v[i];
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    addedge(u, v);
  }
  dfs1(r);
  dfs2(r, r);
  build(1, 1, n);
  while(m--) {
    int op, x, y, z; cin >> op;
    if(op == 1) {
      cin >> x >> y >> z;
      update_range(x, y, z%MOD);
    } else if(op == 2) {
      cin >> x >> y;
      cout << query_range(x, y) << endl;
    } else if(op == 3) {
      cin >> x >> z;
      update_tree(x, z%MOD);
    } else {
      cin >> x;
      cout << query_tree(x) << endl;
    }
  }
  return 0;
}