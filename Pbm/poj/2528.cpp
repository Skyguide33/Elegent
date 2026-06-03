//2025/9/5
#include <cstdio>
#include <map>
#include <set>
using namespace std;
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N = 20005;

int tree[N<<2], tag[N<<2], ans;
struct Pair { int l, r; } a[10005];

void build(int p, int pl, int pr) {
  tag[p] = 0;
  if(pl == pr) { tree[p] = 0; return; }
  int mid = (pl+pr)>>1;
  build(ls(p), pl, mid);
  build(rs(p), mid+1, pr);
}

void addtag(int p, int pl, int pr, int d) { tag[p] = d; tree[p] = d; }

void push_down(int p, int pl, int pr) {
  if(tag[p]) {
    int mid = (pl+pr)>>1;
    addtag(ls(p), pl, mid, tag[p]);
    addtag(rs(p), mid+1, pr, tag[p]);
    tag[p] = 0;
  }
}

void update(int L, int R, int p, int pl, int pr, int d) {
  if(L <= pl && pr <= R) { addtag(p, pl, pr, d); return; }
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls(p), pl, mid, d);
  if(R > mid) update(L, R, rs(p), mid+1, pr, d);
}

int query(int idx, int p, int pl, int pr) {
  if(pl == pr) return tree[p];
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  int res;
  if(idx <= mid) res = query(idx, ls(p), pl, mid);
  else res = query(idx, rs(p), mid+1, pr);
  return res; 
}

void solve() {
  int n; scanf("%d", &n);
  map<int, int> mp;
  for(int i = 1; i <= n; ++i) {
    scanf("%d %d", &a[i].l, &a[i].r);
    mp[a[i].l] = 0;
    mp[a[i].r] = 0;
  }
  int cnt = 0;
  map<int, int>::iterator it = mp.begin();
  for(; it != mp.end(); ++it) it->second = ++cnt;
  for(int i = 1; i <= n; ++i) {
    a[i].l = mp[a[i].l];
    a[i].r = mp[a[i].r];
  }
  build(1, 1, cnt);
  for(int i = 1; i <= n; ++i) {
    update(a[i].l, a[i].r, 1, 1, cnt, i);
  }
  set<int> st;
  for(int i = 1; i <= cnt; ++i) {
    st.insert(query(i, 1, 1, cnt));
  }
  int ans = st.size();
  if(st.count(0)) --ans;
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while(T--) solve();
  return 0;
}