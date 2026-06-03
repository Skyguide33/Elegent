//2025/10/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 500005
#define lc t[u].ls
#define rc t[u].rs
const double alpha = 0.75;

struct Point {
  int dim[2], val;
  Point() {}
  Point(int x, int y, int v) {
    dim[0] = x; dim[1] = y; val = v;
  }
} order[N];

struct kd_tree {
  int ls, rs, mi[2], ma[2], sum, siz;
  Point p;
} t[N];

int cnt, tot, root, top, tree_stack[N], now;

bool cmp(Point a, Point b) { return a.dim[now] < b.dim[now]; }

void update(int u) {
  for(int i = 0; i < 2; ++i) {
    t[u].mi[i] = t[u].ma[i] = t[u].p.dim[i];
    if(lc) {
      t[u].mi[i] = min(t[u].mi[i], t[lc].mi[i]);
      t[u].ma[i] = max(t[u].ma[i], t[lc].ma[i]);
    } 
    if(rc) {
      t[u].mi[i] = min(t[u].mi[i], t[rc].mi[i]);
      t[u].ma[i] = max(t[u].ma[i], t[rc].ma[i]);
    }
  }
  t[u].sum = t[lc].sum+t[u].p.val+t[rc].sum;
  t[u].siz = t[lc].siz+1+t[rc].siz;
}

bool notbalance(int u) {
  if(t[lc].siz > alpha*t[u].siz || t[rc].siz > alpha*t[u].siz) return 1;
  return 0;
}

void slap(int u) {
  if(!u) return;
  slap(lc);
  order[++cnt] = t[u].p;
  tree_stack[++top] = u;
  slap(rc);
}

int build(int l, int r, int d) {
  if(l > r) return 0;
  int u;
  if(top) u = tree_stack[top--];
  else u = ++tot;
  int mid = (l+r)>>1;
  now = d;
  nth_element(order+l, order+mid, order+r+1, cmp);
  t[u].p = order[mid];
  lc = build(l, mid-1, d^1);
  rc = build(mid+1, r, d^1);
  update(u);
  return u;
}

void Insert(int &u, Point now, int d) {
  if(!u) {
    if(top) u = tree_stack[top--];
    else u = ++tot;
    lc = rc = 0; t[u].p = now;
    update(u);
    return;
  }
  if(now.dim[d] <= t[u].p.dim[d]) Insert(lc, now, d^1);
  else Insert(rc, now, d^1);
  update(u);
  if(notbalance(u)) {
    cnt = 0;
    slap(u);
    u = build(1, t[u].siz, d);
  }
}

int query(int u, int x1, int y1, int x2, int y2) {
  if(!u) return 0;
  int X1 = t[u].mi[0], Y1 = t[u].mi[1], X2 = t[u].ma[0], Y2 = t[u].ma[1];
  if(x1 <= X1 && x2 >= X2 && y1 <= Y1 && y2 >= Y2) return t[u].sum;
  else if(x1 > X2 || x2 < X1 || y1 > Y2 || y2 < Y1) return 0;
  int ans = 0;
  X1 = t[u].p.dim[0], Y1 = t[u].p.dim[1];
  if(x1 <= X1 && X1 <= x2 && y1 <= Y1 && Y1 <= y2) ans += t[u].p.val;
  ans += query(lc, x1, y1, x2, y2)+query(rc, x1, y1, x2, y2);
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0;
  while(1) {
    int op, x, y, x2, y2, val; cin >> op;
    if(op == 1) {
      cin >> x >> y >> val;
      x ^= ans; y ^= ans; val ^= ans;
      Insert(root, Point(x, y, val), 0); 
    } else if(op == 2) {
      cin >> x >> y >> x2 >> y2;
      x ^= ans; y ^= ans; x2 ^= ans; y2 ^= ans;
      ans = query(root, x, y, x2, y2);
      cout << ans << endl;
    } else break;
  }
  return 0;
}