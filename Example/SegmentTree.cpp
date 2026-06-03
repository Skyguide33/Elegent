//2025/8/16 线段树 区间和模板
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2000005;

int a[N], tree[N<<2], tag[N<<2];
int ls(int &p) { return p<<1; }
int rs(int &p) { return p<<1|1; }

void push_up(int p) {
  tree[p] = tree[ls(p)]+tree[rs(p)];
}

void build(int p, int pl, int pr) {
  tag[p] = 0;
  if(pl == pr) {
    tree[p] = a[pl];
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls(p), pl, mid);
  build(rs(p), mid+1, pr);
  push_up(p);
}

void addtag(int p, int pl, int pr, int d) {
  tag[p] += d;
  tree[p] += (pr-pl+1)*d;
}

void push_down(int p, int pl, int pr) {
  if(tag[p]) {
    int mid = (pl+pr)>>1;
    addtag(ls(p), pl, mid, tag[p]);
    addtag(rs(p), mid+1, pr, tag[p]);
    tag[p] = 0;
  }
}

void update(int L, int R, int p, int pl, int pr, int d) {
  if(L <= pl && pr <= R) {
    addtag(p, pl, pr, d);
    return;
  }
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls(p), pl, mid, d);
  if(R >= mid+1) update(L, R, rs(p), mid+1, pr, d);
  push_up(p);
}

int query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return tree[p];
  push_down(p, pl, pr);
  int res = 0;
  int mid = (pl+pr)>>1;
  if(L <= mid) res += query(L, R, ls(p), pl, mid);
  if(R >= mid+1) res += query(L, R, rs(p), mid+1, pr);
  return res;
}

signed main() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  update(2, 4, 1, 1, n, 4);
  cout << "tt" << endl;
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j) {
      cout << "a(" << i << "," << j << ")=" << query(i, j, 1, 1, n) << endl;
    }
  }
  return 0;
}