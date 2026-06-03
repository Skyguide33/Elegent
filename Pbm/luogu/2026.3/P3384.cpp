//2026/3/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005
#define ls p<<1
#define rs p<<1|1
#define SHOW3(x, y, z) clog << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

namespace FastIO {
  const int SZ = 1<<20;
  char inbuf[SZ], outbuf[SZ];
  int in_left = 0, in_right = 0;
  int out_right = 0;
  
  inline void load() {
    int len = fread(inbuf, 1, SZ, stdin);
    in_left = 0;
    in_right = len;
  }
  
  inline char getchar() {
    if(in_left >= in_right) load();
    if(in_left >= in_right) return EOF;
    return inbuf[in_left++];
  }
  
  inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
      if(ch == '-') f = -1;
      ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
      x = x*10+(ch-'0');
      ch = getchar();
    }
    return x*f;
  }
  
  inline void flush() {
    fwrite(outbuf, 1, out_right, stdout);
    out_right = 0;
  }
  
  inline void putchar(char ch) {
    outbuf[out_right++] = ch;
    if(out_right == SZ) flush();
  }
  
  inline void write(int x) {
    if(x < 0) {
      putchar('-');
      x *= -1;
    }
    if(x > 9) write(x/10);
    putchar(x%10+'0');
  }
  
  struct Flusher {
    ~Flusher() { flush(); }
  } flusher;
}

using namespace FastIO;

struct Edge { int v, nxt; } e[N<<1];
int head[N], cnt;

inline void addedge(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}

int n, mod, fa[N], dep[N], son[N], sz[N], top[N], nw[N], w[N], id[N], idx;
int tree[N<<2], tag[N<<2];

inline void push_up(int p) {
  tree[p] = tree[ls]+tree[rs];
}

void build(int p, int pl, int pr) {
  if(pl == pr) {
    tree[p] = nw[pl];
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls, pl, mid);
  build(rs, mid+1, pr);
  push_up(p);
}

inline void addtag(int p, int pl, int pr, int d) {
  tag[p] = (tag[p]+d)%mod;
  tree[p] = (tree[p]+1ll*d*(pr-pl+1))%mod;
}

inline void push_down(int p, int pl, int pr) {
  if(!tag[p]) return;
  int mid = (pl+pr)>>1;
  addtag(ls, pl, mid, tag[p]);
  addtag(rs, mid+1, pr, tag[p]);
  tag[p] = 0;
}

void update(int L, int R, int p, int pl, int pr, int d) {
  if(L <= pl && pr <= R) return addtag(p, pl, pr, d);
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls, pl, mid, d);
  if(R > mid) update(L, R, rs, mid+1, pr, d);
  push_up(p);
}

ll query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return tree[p]%mod;
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  int res = 0;
  if(L <= mid) res += query(L, R, ls, pl, mid);
  if(R > mid) res += query(L, R, rs, mid+1, pr);
  return res%mod;
}

void dfs1(int u, int father) {
  fa[u] = father; sz[u] = 1; dep[u] = dep[father]+1; 
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v == father) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if(sz[v] > sz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  top[u] = t; id[u] = ++idx; nw[idx] = w[u];
  if(!son[u]) return;
  dfs2(son[u], t);
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if(v != fa[u] && v != son[u]) dfs2(v, v);
  }
}

inline void update_path(int x, int y, int z) {
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    update(id[top[x]], id[x], 1, 1, n, z);
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  update(id[x], id[y], 1, 1, n, z);
}

inline void update_tree(int x, int z) {
  update(id[x], id[x]+sz[x]-1, 1, 1, n, z);
}

inline int query_path(int x, int y) {
  int res = 0;
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    res = (res+query(id[top[x]], id[x], 1, 1, n))%mod;
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  return (res+query(id[x], id[y], 1, 1, n))%mod;
}

inline int query_tree(int x) {
  return query(id[x], id[x]+sz[x]-1, 1, 1, n);
}

int main() {
  n = read(); int m = read(), r = read(); mod = read();
  for(int i = 1; i <= n; ++i) w[i] = read();
  for(int i = 1; i < n; ++i) {
    int u = read(), v = read(); 
    addedge(u, v); addedge(v, u);
  }
  dfs1(r, 0);
  dfs2(r, r);
  build(1, 1, n);
  int op, x, y, z;
  while(m--) {
    op = read();
    if(op == 1) {
      x = read(), y = read(), z = read();
      update_path(x, y, z);
    }
    else if(op == 2) {
      x = read(), y = read();
      write(query_path(x, y)), putchar('\n');
    }
    else if(op == 3) {
      x = read(), z = read();
      update_tree(x, z);
    }
    else write(query_tree(read())), putchar('\n');
  }
  return 0;
}