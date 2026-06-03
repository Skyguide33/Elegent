//2025/8/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls (p<<1)
#define rs (p<<1|1)
const int MOD = 10007;

int tree[3][400005], tag[3][400005], L, R;

void build(int p, int pl, int pr) {
  memset(tree, 0, sizeof(tree));
  memset(tag, 0, sizeof(tag));
}

void addtag(int op, int p, int pl, int pr, int d) {
  int len = pr-pl+1;
  if(op == 0) {
    tag[0][p] = (tag[0][p]+d)%MOD;
    tree[2][p] = (tree[2][p]+3*tree[1][p]*d%MOD+3*tree[0][p]*d%MOD*d+(len*d%MOD)*(d*d%MOD))%MOD;
    tree[1][p] = (tree[1][p]+2*tree[0][p]*d%MOD+d*d%MOD*len)%MOD;
    tree[0][p] = (tree[0][p]+len*d)%MOD;
  } else if(op == 1) {
    if(d != 1) {
      tag[1][p] = (tag[1][p]? (tag[1][p]*d)%MOD: d);
      tag[0][p] = tag[0][p]*d%MOD;
      tree[2][p] = (tree[2][p]*d%MOD)*(d*d%MOD)%MOD;
      tree[1][p] = tree[1][p]*(d*d%MOD)%MOD;
      tree[0][p] = (tree[0][p]*d)%MOD;
    }
  } else {
    tag[2][p] = d; tag[0][p] = tag[1][p] = 0;
    tree[2][p] = len*d%MOD*(d*d%MOD)%MOD;
    tree[1][p] = len*d%MOD*d%MOD;
    tree[0][p] = len*d%MOD;
  }
}

void push_down(int p, int pl, int pr) {
  int mid = (pl+pr)>>1;
  for(int i = 2; i >= 0; --i) 
    if(tag[i][p]) {
      addtag(i, ls, pl, mid, tag[i][p]);
      addtag(i, rs, mid+1, pr, tag[i][p]);
      tag[i][p] = 0;
    }
}

void update(int op, int p, int pl, int pr, int c) {
  if(L <= pl && pr <= R) {
    addtag(op, p, pl, pr, c);
    return;
  }
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(op, ls, pl, mid, c);
  if(R > mid) update(op, rs, mid+1, pr, c);
  for(int i = 0; i <= 2; ++i) tree[i][p] = (tree[i][ls]+tree[i][rs])%MOD;
}

int query(int p, int pl, int pr, int c) {
  if(L <= pl && pr <= R) return tree[c][p];
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  int res = 0;
  if(L <= mid) res = (res+query(ls, pl, mid, c))%MOD;
  if(R > mid) res = (res+query(rs, mid+1, pr, c))%MOD;
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, op, c; 
  while(cin >> n >> m) {
    if(n == 0) return 0;
    build(1, 1, n);
    while(m--) {
      cin >> op >> L >> R >> c;
      if(op < 4) update(op-1, 1, 1, n, c);
      else cout << query(1, 1, n, c-1) << endl;
    }
  }
}