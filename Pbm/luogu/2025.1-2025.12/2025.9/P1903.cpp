//2025/9/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int a[133334], pos[133334], st[53], ed[53], num[1000005], ans[133334], block, t, n, l = 1, r, cnt, tt;

struct quest {
  int id, l, r, tt;
} q[133334];

struct chge {
  int id, p, old1, new1;
} rr[133334];

void init() {
  block = pow(n, 2./3);
  t = n/block;
  if(n%block) ++t;
  for(int i = 1; i <= n; ++i) pos[i] = (i-1)/block+1;
}

void change(int p, int c) {
  if(l <= p && p <= r && --num[a[p]] == 0) --cnt;
  a[p] = c;
  if(l <= p && p <= r && ++num[a[p]] == 1) ++cnt;
}

bool cmp(quest &x, quest &y) { 
  if(pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
  if(pos[x.r] != pos[y.r]) {
    if(pos[x.l]%2) return pos[x.r] < pos[y.r];
    return pos[x.r] > pos[y.r];
  }
  if(pos[x.r]%2) return x.tt < y.tt;
  return x.tt > y.tt;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  init();
  int idq = 0, idr = 0;
  while(m--) {
    char ch; cin >> ch;
    if(ch == 'Q') {
      q[idq].id = idq; q[idq].tt = idr;
      cin >> q[idq].l >> q[idq].r;
      ++idq;
    } else {
      ++idr;
      cin >> rr[idr].p >> rr[idr].new1;
      rr[idr].id = idr, rr[idr].old1 = a[rr[idr].p];
      change(rr[idr].p, rr[idr].new1);
    }
  }
  for(int i = idr; i >= 1; --i) change(rr[i].p, rr[i].old1);
  sort(q, q+idq, cmp);
  for(int i = 0; i < idq; ++i) {
    while(tt < q[i].tt) {
      ++tt;
      change(rr[tt].p, rr[tt].new1);
    }
    while(tt > q[i].tt) {
      change(rr[tt].p, rr[tt].old1);
      --tt;
    }
    while(l < q[i].l) 
      if(--num[a[l++]] == 0) --cnt;
    while(l > q[i].l)
      if(++num[a[--l]] == 1) ++cnt; 
    while(r < q[i].r) 
      if(++num[a[++r]] == 1) ++cnt;
    while(r > q[i].r)
      if(--num[a[r--]] == 0) --cnt; 
    ans[q[i].id] = cnt;
  }
  for(int i = 0; i < idq; ++i) cout << ans[i] << endl;
  return 0;
}