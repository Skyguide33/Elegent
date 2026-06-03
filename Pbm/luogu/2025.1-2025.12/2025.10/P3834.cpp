//2025/10/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005
int a[N], b[N], root[N], cnt;

struct { int L, R, sum; } tree[N<<5];

int update(int pre, int pl, int pr, int x) {
  int rt = ++cnt;
  tree[rt].L = tree[pre].L;
  tree[rt].R = tree[pre].R;
  tree[rt].sum = tree[pre].sum+1;
  int mid = (pl+pr)>>1;
  if(pl < pr) {
    if(x <= mid) tree[rt].L = update(tree[pre].L, pl, mid, x);
    else tree[rt].R = update(tree[pre].R, mid+1, pr, x);
  }
  return rt;
}

int query(int u, int v, int pl, int pr, int k) {
  if(pl == pr) return pl;
  int x = tree[tree[v].L].sum-tree[tree[u].L].sum;
  int mid = (pl+pr)>>1;
  if(k <= x) {
    return query(tree[u].L, tree[v].L, pl, mid, k);
  } else {
    return query(tree[u].R, tree[v].R, mid+1, pr, k-x);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; b[i] = a[i];
  }
  sort(b+1, b+n+1);
  int siz = unique(b+1, b+n+1)-b-1;
  for(int i = 1; i <= n; ++i) {
    int x = lower_bound(b+1, b+siz+1, a[i])-b;
    root[i] = update(root[i-1], 1, siz, x);
  }
  while(m--) {
    int x, y, k; cin >> x >> y >> k;
    int t = query(root[x-1], root[y], 1, siz, k);
    cout << b[t] << endl;
  }
  return 0;
}