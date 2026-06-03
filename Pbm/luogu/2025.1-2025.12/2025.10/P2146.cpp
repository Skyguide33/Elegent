//2025/10/12 线段树+树链部分
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005
#define ls p<<1
#define rs p<<1|1

// lazy_tag: 1全部置1  -1全部置0

int tree[N<<2], tag[N<<2];

void push_up(int p) {
  tree[p] = tree[ls]+tree[rs];
}

void addtag(int p, int pl, int pr, int d) {
  tag[p] = d;
  if(d == -1) tree[p] = 0;
  else tree[p] = pr-pl+1;
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
  int mid = (pl+pr)>>1, res = 0;
  if(L <= mid) res += query(L, R, ls, pl, mid);
  if(R > mid) res += query(L, R, rs, mid+1, pr);
  return res;
}

struct edge { int to, next; } e[N<<1];
int head[N], son[N], fa[N], siz[N], dep[N], top[N];
int pos[N], cnt, seq, n;

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
  pos[u] = ++seq;
  if(!son[u]) return;
  dfs2(son[u], topu);
  for(int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if(v != fa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

int inst(int x) {
  int adds = 0;
  while(top[x] != 0) {
    adds += pos[x]-pos[top[x]]+1-query(pos[top[x]], pos[x], 1, 1, n);
    update(pos[top[x]], pos[x], 1, 1, n, 1);
    x = fa[top[x]];
  }
  adds += pos[x]-pos[0]+1-query(pos[0], pos[x], 1, 1, n);
  update(pos[0], pos[x], 1, 1, n, 1);
  return adds;
}

int uinst(int x) {
  int dels = query(pos[x], pos[x]+siz[x]-1, 1, 1, n);
  update(pos[x], pos[x]+siz[x]-1, 1, 1, n, -1);
  return dels;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n-1; ++i) {
    int t; cin >> t;
    addedge(i, t);
  }
  fa[0] = N-1;
  dfs1(0);
  dfs2(0, 0);
  int m; cin >> m;
  while(m--) {
    string op; int x; cin >> op >> x;
    if(op == "install") cout << inst(x) << endl;
    else cout << uinst(x) << endl;
  }
  return 0;
}