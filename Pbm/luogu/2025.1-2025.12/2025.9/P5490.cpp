//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ls p<<1
#define rs p<<1|1
#define N 200005

int xx[N], tag[N<<2];
ll len[N<<2];

struct ScanLine {
  int y, lx, rx, inout;
  ScanLine() {}
  ScanLine(int y, int x1, int x2, int io):
    y(y), lx(x1), rx(x2), inout(io) {}
} line[N];
bool cmp(ScanLine &a, ScanLine &b) { return a.y < b.y; }

void push_up(int p, int pl, int pr) {
  if(tag[p]) len[p] = xx[pr]-xx[pl];
  else if(pl+1 == pr) len[p] = 0;
  else len[p] = len[ls]+len[rs];
}

void update(int L, int R, int io, int p, int pl, int pr) {
  if(L <= pl && pr <= R) {
    tag[p] += io;
    return push_up(p, pl, pr);
  }
  if(pl+1 == pr) return;
  int mid = (pl+pr)>>1;
  if(L <= mid) update(L, R, io, ls, pl, mid);
  if(R > mid) update(L, R, io, rs, mid, pr);
  push_up(p, pl ,pr);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, cnt = 0; cin >> n;
  while(n--) {
    int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    line[++cnt] = ScanLine(y1, x1, x2, 1);
    xx[cnt] = x1;
    line[++cnt] = ScanLine(y2, x1, x2, -1);
    xx[cnt] = x2;
  }
  sort(xx+1, xx+cnt+1);
  sort(line+1, line+cnt+1, cmp);
  int num = unique(xx+1, xx+cnt+1)-(xx+1);
  ll ans = 0;
  for(int i = 1; i <= cnt; ++i) {
    ans += 1ll*len[1]*(line[i].y-line[i-1].y);
    update(lower_bound(xx+1, xx+num+1, line[i].lx)-xx,
          lower_bound(xx+1, xx+num+1, line[i].rx)-xx,
          line[i].inout, 1, 1, num);
  }
  cout << ans << endl;
  return 0;
}