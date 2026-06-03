//2025/9/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
const int N = 50005;

int tree[N<<2], tag[N<<2], n;

void push_up(int p) { tree[p] = tree[ls(p)]+tree[rs(p)]; }

void addtag(int p, int pl, int pr, int d) {
  tag[p] = d? 1: -1; 
  tree[p] = d? pr-pl+1: 0;
}

void push_down(int p, int pl, int pr) {
  if(tag[p]) {
    int d = max(0, tag[p]);
    int mid = (pl+pr)>>1;
    addtag(ls(p), pl, mid, d);
    addtag(rs(p), mid+1, pr, d);
    tag[p] = 0;
  }
}

void update(int L, int R, int p, int pl, int pr, int d) {
  if(L <= pl && pr <= R) { addtag(p, pl, pr, d); return; }
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, ls(p), pl, mid, d);
  if(R > mid) update(L, R, rs(p), mid+1, pr, d);
  push_up(p);
}

int query(int L, int R, int p, int pl, int pr) {
  if(L <= pl && pr <= R) return tree[p]; 
  push_down(p, pl, pr);
  int mid = (pl+pr)>>1;
  int res = 0;
  if(L <= mid) res += query(L, R, ls(p), pl, mid);
  if(R > mid) res += query(L, R, rs(p), mid+1, pr);
  return res;
}

void solve() {
  int m; cin >> n >> m;
  addtag(1, 0, n-1, 0);
  while(m--) {
    int k, a, b; cin >> k >> a >> b;
    if(k == 1) {
      if(query(a, n-1, 1, 0, n-1) == n-a) {
        cout << "Can not put any one." << endl;
        continue;
      }
      int l = a, r = n-1;
      while(l < r) {
        int mid = (l+r)>>1;
        if(query(a, mid, 1, 0, n-1) < mid-a+1) r = mid;
        else l = mid+1;
      }
      int left = l, right;
      if(n-left-query(left, n-1, 1, 0, n-1) < b) {
        l = left, r = n-1;
        while(l < r) {
          int mid = (l+r+1)>>1;
          if(query(mid, n-1, 1, 0, n-1) < n-mid) l = mid;
          else r = mid-1;
        }
        right = l;
      } else {
        l = left, r = n-1;
        while(l < r) {
          int mid = (l+r)>>1;
          if(mid-left+1-query(left, mid, 1, 0, n-1) >= b) r = mid;
          else l = mid+1;
        }
        right = l;
      }
      cout << left << ' ' << right << endl;
      update(left, right, 1, 0, n-1, 1);
    } else {
      cout << query(a, b, 1, 0, n-1) << endl;
      update(a, b, 1, 0, n-1, 0);
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}