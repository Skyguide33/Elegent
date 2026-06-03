//2025/9/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N = 1e6+5;

ll sum[N<<2];
int ma[N<<2], se[N<<2], num[N<<2];

void push_up(int p) {
  sum[p] = sum[ls(p)]+sum[rs(p)];
  ma[p] = max(ma[ls(p)], ma[rs(p)]);
  se[p] = max(se[ls(p)], se[rs(p)]);
  if(ma[ls(p)] == ma[rs(p)]) num[p] = num[ls(p)]+num[rs(p)];
  else {
    se[p] = max(se[p], min(ma[ls(p)], ma[rs(p)]));
    num[p] = ma[ls(p)] > ma[rs(p)]? num[ls(p)]: num[rs(p)];
  }
}

void build(int p, int pl, int pr) {
  if(pl == pr) {
    cin >> sum[p];
    ma[p] = sum[p]; se[p] = -1; num[p] = 1;
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls(p), pl, mid);
  build(rs(p), mid+1, pr);
  push_up(p);
}

void addtag(int p, int x) {
  if(x >= ma[p]) return;
  sum[p] -= 1ll*num[p]*(ma[p]-x);
  ma[p] = x;
}

void push_down(int p) {
  addtag(ls(p), ma[p]);
  addtag(rs(p), ma[p]);
}

void update(int L, int R, int p, int pl, int pr, int x) {
  if(x >= ma[p]) return;
  if(L <= pl && pr <= R && se[p] < x) { addtag(p, x); return; }
  push_down(p);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls(p), pl, mid, x);
  if(R > mid) update(L, R, rs(p), mid+1, pr, x);
  push_up(p);
}

int queryMax(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return ma[p];
  push_down(p);
  int mid = (pl+pr)>>1;
  int res = 0;
  if(L <= mid) res = queryMax(L, R, ls(p), pl, mid);
  if(R > mid) res = max(res, queryMax(L, R, rs(p), mid+1, pr));
  return res;
}

ll querySum(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return sum[p];
  push_down(p);
  int mid = (pl+pr)>>1;
  ll res = 0;
  if(L <= mid) res += querySum(L, R, ls(p), pl, mid);
  if(R > mid) res += querySum(L, R, rs(p), mid+1, pr);
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  build(1, 1, n);
  while(m--) {
    int op, l, r, t; cin >> op >> l >> r;
    if(op == 0) {
      cin >> t;
      update(l, r, 1, 1, n, t);
    } else if(op == 1) cout << queryMax(l, r, 1, 1, n) << endl;
    else cout << querySum(l, r, 1, 1, n) << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}