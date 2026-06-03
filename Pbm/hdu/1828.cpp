//2025/9/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
#define N 100005

ll xx[N], yy[N], tag[N<<2], len[N<<2];

struct ScanLine {
  ll y, lx, rx, inout;
} row[N], col[N];

bool cmp(ScanLine &a, ScanLine &b) { 
  if(a.y == b.y) return a.inout > b.inout;
  return a.y < b.y; 
}

void push_up(ll p, ll pl, ll pr, ll *arr) {
  if(tag[p]) len[p] = arr[pr]-arr[pl];
  else if(pl+1 == pr) len[p] = 0;
  else len[p] = len[ls]+len[rs];
}

void update(ll L, ll R, ll io, ll p, ll pl, ll pr, ll *arr) {
  if(L <= pl && pr <= R) {
    tag[p] += io;
    return push_up(p, pl, pr, arr);
  }
  if(pl+1 == pr) return;
  ll mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, io, ls, pl, mid, arr);
  if(R > mid) update(L, R, io, rs, mid, pr, arr);
  push_up(p, pl, pr, arr);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, cnt = 0; cin >> n;
  while(n--) {
    ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    row[++cnt] = {y1, x1, x2, 1}; col[cnt] = {x1, y1, y2, 1};
    xx[cnt] = x1; yy[cnt] = y1;
    row[++cnt] = {y2, x1, x2, -1}; col[cnt] = {x2, y1, y2, -1};
    xx[cnt] = x2; yy[cnt] = y2;
  }
  sort(xx+1, xx+cnt+1); sort(yy+1, yy+cnt+1);
  sort(row+1, row+cnt+1, cmp); sort(col+1, col+cnt+1, cmp);
  ll numr = unique(xx+1, xx+cnt+1)-(xx+1), numc = unique(yy+1, yy+cnt+1)-(yy+1);
  ll ans = 0, pre;
  for(ll i = 1; i <= cnt; ++i) {
    pre = len[1];
    update(lower_bound(xx+1, xx+numr+1, row[i].lx)-xx,
          lower_bound(xx+1, xx+numr+1, row[i].rx)-xx,
          row[i].inout, 1, 1, numr, xx);
    ans += abs(len[1]-pre);
  }
  for(ll i = 1; i <= cnt; ++i) {
    pre = len[1];
    update(lower_bound(yy+1, yy+numc+1, col[i].lx)-yy,
          lower_bound(yy+1, yy+numc+1, col[i].rx)-yy,
          col[i].inout, 1, 1, numc, yy);
    ans += abs(len[1]-pre);
  }
  cout << ans << endl;
  return 0;
}