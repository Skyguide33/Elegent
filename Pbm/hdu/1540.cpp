//2025/9/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
const int N = 50005;

int tree[N<<2], suf[N<<2], pre[N<<2], his[N];

void push_up(int p, int len) {
  pre[p] = pre[ls];
  suf[p] = suf[rs];
  if(pre[ls] == (len-(len>>1))) pre[p] = pre[ls]+pre[rs];
  if(suf[rs] == (len>>1)) suf[p] = suf[rs]+suf[ls];
}

void build(int p, int pl, int pr) {
  if(pl == pr) { tree[p] = pre[p] = suf[p] = 1; return; }
  int mid = (pl+pr)>>1;
  build(ls, pl, mid);
  build(rs, mid+1, pr);
  push_up(p, pr-pl+1);
}

void update(int x, int c, int p, int pl, int pr) {
  if(pl == pr) { tree[p] = suf[p] = pre[p] = c; return; }
  int mid = (pl+pr)>>1;
  if(x <= mid) update(x, c, ls, pl, mid);
  else update(x, c, rs, mid+1, pr);
  push_up(p, pr-pl+1);
}

int query(int x, int p, int pl, int pr) {
  if(pl == pr) return tree[p];
  int mid = (pl+pr)>>1;
  if(x <= mid) {
    if(x >= mid-suf[ls]+1) return suf[ls]+pre[rs];
    else return query(x, ls, pl, mid);
  } else {
    if(x <= mid+pre[rs]) return pre[rs]+suf[ls];
    else return query(x, rs, mid+1, pr);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, cnt;
  while(cin >> n >> m) {
    cnt = 0;
    build(1, 1, n);
    while(m--) {
      char op; int x; cin >> op;
      if(op == 'Q') {
        cin >> x;
        cout << query(x, 1, 1, n) << endl;
      }
      else if(op == 'D') {
        cin >> x;
        his[++cnt] = x;
        update(x, 0, 1, 1, n);
      } else update(his[cnt--], 1, 1, 1, n);
    }
  }
  
  return 0;
}