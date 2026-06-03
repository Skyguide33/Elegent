//2025/9/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
#define N 1000005

int MOD;

struct Tree {
  int sum, tag[2], len, pl, pr, mid;
} tree[N<<2];

void push_up(int p) {
  tree[p].sum = (tree[ls].sum+tree[rs].sum)%MOD;
}

void build(int p, int L, int R) {
  int mid = (L+R)>>1;
  tree[p] = {0, {1, 0}, R-L+1, L, R, mid};
  if(L == R) { 
    cin >> tree[p].sum; 
    tree[p].sum %= MOD;
    return; 
  }
  build(ls, L, mid);
  build(rs, mid+1, R);
  push_up(p);
}

void addtag(int p, int op, int d) {
  if(op) {
    tree[p].tag[1] = (tree[p].tag[1]+d)%MOD;
    tree[p].sum = (tree[p].sum+1ll*tree[p].len*d)%MOD;
  } else {
    tree[p].tag[0] = 1ll*tree[p].tag[0]*d%MOD;
    tree[p].tag[1] = 1ll*tree[p].tag[1]*d%MOD;
    tree[p].sum = 1ll*tree[p].sum*d%MOD;
  }
}

void push_down(int p) {
  if(tree[p].tag[0] != 1) {
    addtag(ls, 0, tree[p].tag[0]);
    addtag(rs, 0, tree[p].tag[0]);
    tree[p].tag[0] = 1; 
  }
  if(tree[p].tag[1]) {
    addtag(ls, 1, tree[p].tag[1]);
    addtag(rs, 1, tree[p].tag[1]);
    tree[p].tag[1] = 0;
  }
}

void update(int L, int R, int p, int op, int d) {
  if(L <= tree[p].pl && tree[p].pr <= R) return addtag(p, op, d);
  push_down(p);
  if(L <= tree[p].mid) update(L, R, ls, op, d);
  if(R > tree[p].mid) update(L, R, rs, op, d);
  push_up(p);
}

int query(int L, int R, int p) {
  if(L <= tree[p].pl && tree[p].pr <= R) return tree[p].sum;
  push_down(p);
  int res = 0;
  if(L <= tree[p].mid) res = query(L, R, ls);
  if(R > tree[p].mid) res = (res+query(L, R, rs))%MOD;
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q >> MOD;
  build(1, 1, n);
  while(q--) {
    int op, x, y, k; cin >> op >> x >> y;
    if(op == 3) cout << query(x, y, 1) << endl;
    else update(x, y, 1, op-1, (cin >> k, k));
  }
  return 0;
}