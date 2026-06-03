//2025/11/2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
#define N 100005

int tree[N<<2], tag[N<<2], sum[N<<2], a[N], n, m, q;

struct Operation { int op, l, r; } b[N];

void push_up(int p) {
  tree[p] = tree[ls]+tree[rs];
}

void build(int p, int pl, int pr, int k) {
  tag[p] = -1;
  if(pl == pr) {
    tree[p] = (a[pl] >= k? 1: 0);
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls, pl, mid, k);
  build(rs, mid+1, pr, k);
  push_up(p);
}

void addtag(int p, int pl, int pr, int d) {
  tag[p] = d;
  tree[p] = (pr-pl+1)*d;
}

void push_down(int p, int pl, int pr) {
  if(tag[p] != -1) {
    int mid = (pl+pr)>>1;
    addtag(ls, pl, mid, tag[p]);
    addtag(rs, mid+1, pr, tag[p]);
    tag[p] = -1;
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


bool check(int k) {
  build(1, 1, n, k);
  for(int i = 1; i <= m; ++i) {
    int sum = query(b[i].l, b[i].r, 1, 1, n);
    if(b[i].op) {
      if(sum) update(b[i].l, b[i].l+sum-1, 1, 1, n, 1);
      if(b[i].r-b[i].l+1-sum) update(b[i].l+sum, b[i].r, 1, 1, n, 0);
    } else {
      if(sum) update(b[i].r-sum+1, b[i].r, 1, 1, n, 1);
      if(b[i].r-b[i].l+1-sum) update(b[i].l, b[i].r-sum, 1, 1, n, 0);
    }
  }
  return query(q, q, 1, 1, n);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i].op >> b[i].l >> b[i].r;
  int l = 0, r = n; cin >> q;
  while(l < r) {
    int mid = (l+r+1)>>1;
    if(check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
}