//2025/8/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll tree[400005];
int ls(int& p) { return p<<1; }
int rs(int& p) { return p<<1|1; }

void push_up(int p) {
  tree[p] = tree[ls(p)]+tree[rs(p)];
}

void build(int p, int pl, int pr) {
  if(pl == pr) {
    cin >> tree[p];
    return;
  }
  int mid = (pl+pr)>>1;
  build(ls(p), pl, mid);
  build(rs(p), mid+1, pr);
  push_up(p);
}

void update(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R && tree[p] == pr-pl+1) return;
  if(pl == pr) {
    tree[p] = sqrt(1.0*tree[p]);
    return;
  } 
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls(p), pl, mid);
  if(R > mid) update(L, R, rs(p), mid+1, pr);
  push_up(p);
  return;
}

ll query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return tree[p];
  ll res = 0;
  int mid = (pl+pr)>>1;
  if(L <= mid) res += query(L, R, ls(p), pl, mid);
  if(R > mid) res += query(L, R, rs(p), mid+1, pr);
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, cnt = 0; 
  while(cin >> n) {
    build(1, 1, n);
    int m; cin >> m;
    cout << "Case #" << ++cnt << ":\n";
    while(m--) {
      int t, x, y; cin >> t >> x >> y;
      if(x > y) swap(x, y);
      if(t == 0) update(x, y, 1, 1, n);
      else cout << query(x, y, 1, 1, n) << '\n';
    }
    cout << '\n';
  }
  return 0;
}