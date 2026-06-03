//2026/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
#define N 200005

int tr[N<<2], tag[N<<2];

inline void push_up(int p) {
  tr[p] = max(tr[ls], tr[rs]);
}

void build(int p, int pl, int pr) {
  tag[p] = 0;
  if(pl == pr) {
    tr[p] = 1e9;
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls, pl, mid);
  build(rs, mid+1, pr);
  push_up(p);
}

void addtag(int p, int pl, int pr, int d) {
  if(tag[p] == 0) tag[p] = d;
  else tag[p] = min(tag[p], d);
  tr[p] = min(tr[p], d);
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
  if(L <= pl && pr <= R) return tr[p];
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1, res = 0;
  if(L <= mid) res = query(L, R, ls, pl, mid);
  if(R > mid) res = max(res, query(L, R, rs, mid+1, pr));
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  build(1, 1, n);
  bool flag = 1;
  while(m--) {
    int l, r, v; cin >> l >> r >> v;
    if(flag) {
      update(l, r, 1, 1, n, v);
      if(query(l, r, 1, 1, n) != v) flag = 0;
    }
  }
  if(flag) {
    cout << "Yes" << endl;
    for(int i = 1; i <= n; ++i) cout << query(i, i, 1, 1, n) << ' ';
    cout << endl;
  } else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}