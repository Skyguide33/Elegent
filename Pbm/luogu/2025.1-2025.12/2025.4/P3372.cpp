//2025/4/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
const int N = 100000;

struct node {
  int l, r;
  ll data, tag = 0;
} b[4*N+5];
ll a[N+5];


void push_up(int p) { b[p].data = b[ls(p)].data + b[rs(p)].data; }

void build(int pl, int pr, int p=1) {
  b[p].l = pl; b[p].r = pr;
  if(pl == pr) { b[p].data = a[pl]; return; }
  int mid = (pl+pr) >> 1;
  build(pl, mid, ls(p));
  build(mid+1, pr, rs(p));
  push_up(p);
}

void addtag(ll d, int p=1) {
  b[p].tag += d;
  b[p].data += d * (b[p].r-b[p].l+1);
  return;
}

void push_down(int p) {
  if(b[p].tag) {
    addtag(b[p].tag, ls(p));
    addtag(b[p].tag, rs(p));
    b[p].tag = 0;
  }
}

void update(int L, int R, ll d, int p=1) {
  if(L <= b[p].l && b[p].r <= R) {
    addtag(d, p);
    return;
  }
  push_down(p);
  int mid = (b[p].l+b[p].r) >> 1;
  if(L <= mid) update(L, R, d, ls(p));
  if(R > mid) update(L, R, d, rs(p));
  push_up(p);
}

ll query(int L, int R, int p=1) {
  if(L <= b[p].l && b[p].r <= R) return b[p].data;
  push_down(p);
  int mid = (b[p].l+b[p].r) >> 1;
  ll res = 0;
  if(L <= mid) res += query(L, R, ls(p));
  if(R > mid) res += query(L, R, rs(p));
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  build(1, n);
  while(m--) {
    int opt, x, y; cin >> opt >> x >> y;
    if(opt == 1) {
      ll k; cin >> k;
      update(x, y, k);
    } else cout << query(x, y) << endl;
  }
  return 0;
}