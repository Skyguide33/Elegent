//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls (p<<1)
#define rs (p<<1|1)
const int MOD = 10007;

unsigned tree[4][400005], tag[4][400005];

void addtag(int op, int p, int pl, int pr, int d);

inline void push_up(int &p) {
  for(int i = 1; i <= 3; ++i) {
    tree[i][p] = (tree[i][ls]+tree[i][rs])%MOD;
  }
}

void build(int p, int pl, int pr) {
  memset(tree, 0, sizeof(tree));
  memset(tag, 0, sizeof(tag));
}

void push_down(int p, int pl, int pr) {
  for(int i = 1; i <= 3; ++i) {
    if(tag[i][p]) {
      int mid = (pl+pr)>>1;
      addtag(i, ls, pl, mid, tag[i][p]);
      addtag(i, rs, mid+1, pr, tag[i][p]);
      tag[i][p] = 0;
      break;
    }
  }
}

void addtag(int op, int p, int pl, int pr, int d) {
  if(!tag[op][p] && pl < pr) push_down(p, pl, pr);
  int len = pr-pl+1;
  if(op == 1) {
    tag[1][p] = (tag[1][p]+d)%MOD;
    tree[3][p] = (tree[3][p]+3*tree[2][p]*d%MOD+3*tree[1][p]*d%MOD*d+(len*d%MOD)*(d*d%MOD))%MOD;
    tree[2][p] = (tree[2][p]+2*tree[1][p]*d%MOD+d*d%MOD*len)%MOD;
    tree[1][p] = (tree[1][p]+len*d)%MOD;
  } else if(op == 2) {
    if(d != 1) {
      // cout << tree[1][p] << ' ' << tree[2][p] << ' ' << tree[3][p] << endl;
      // cout << (tree[1][p]*d)%MOD << ' ' << tree[2][p]*(d*d%MOD)%MOD << ' ' << (tree[3][p]*d%MOD)*(d*d%MOD)%MOD << endl;
      tag[2][p] = (tag[2][p]? (tag[2][p]*d)%MOD: d);
      tree[3][p] = (tree[3][p]*d%MOD)*(d*d%MOD)%MOD;
      tree[2][p] = tree[2][p]*(d*d%MOD)%MOD;
      tree[1][p] = (tree[1][p]*d)%MOD;
    }
  } else {
    tag[3][p] = d;
    tree[3][p] = len*d%MOD*(d*d%MOD);
    tree[2][p] = len*d%MOD*d%MOD;
    tree[1][p] = len*d%MOD;
  }
}

void update(int op, int L, int R, int p, int pl, int pr, int c) {
  if(L <= pl && pr <= R) {
    addtag(op, p, pl, pr, c);
    return;
  }
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(op, L, R, ls, pl, mid, c);
  if(R > mid) update(op, L, R, rs, mid+1, pr, c);
  push_up(p);
}

int query(int L, int R, int p, int pl, int pr, int c) {
  if(L <= pl && pr <= R) return tree[c][p];
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  int res = 0;
  if(L <= mid) res = (res+query(L, R, ls, pl, mid, c))%MOD;
  if(R > mid) res = (res+query(L, R, rs, mid+1, pr, c))%MOD;
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; 
  while(cin >> n >> m) {
    if(n == 0) return 0;
    build(1, 1, n);
    while(m--) {
      int op, x, y, c; cin >> op >> x >> y >> c;
      if(x > y) swap(x, y);
      if(op < 4) update(op, x, y, 1, 1, n, c);
      else cout << query(x, y, 1, 1, n, c) << endl;

      // cout << endl;
      // cout << "op=" << op << ' ' << x << ' ' << y << ' ' << c << endl;
      // for(int i = 1; i <= n*2; i *= 2) {
      //   for(int j = i; j < i*2; ++j) {
      //     for(int k = 1; k <= 3; ++k) cout << tree[k][j] << ',';
      //     for(int k = 1; k <= 3; ++k) cout << tag[k][j] << ':';
      //     cout << "  ";
      //   }
      //   cout << endl;
      // }
    }
  }
}