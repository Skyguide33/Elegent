//2025/9/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[320][10][10], pos[100005], st[320], ed[320], dv[10], block, t; 

bool getres(int num, int d, int c) {
  num /= dv[d];
  if(num%10 == c) return 1;
  return 0;
}

void init(int l, int r) {
  int n = r-l+1;
  block = sqrt(n);
  t = n/block;
  if(n%block) ++t;
  for(int i = l; i <= r; ++i) pos[i] = (i-l)/block+1;
  for(int i = 1; i <= t; ++i) {
    st[i] = (i-1)*block+l;
    ed[i] = i*block+l-1;
  }
  ed[t] = r;
  memset(b, 0, sizeof(b));
  for(int i = 1; i <= t; ++i) {
    for(int j = st[i]; j <= ed[i]; ++j) {
      int num = a[j];
      for(int d = 0; d < 10; ++d) {
        ++b[i][d][num%10];
        num /= 10;
      }
    }
  }
}

void change(int p, int y) {
  int old = a[p];
  a[p] = y;
  p = pos[p];
  for(int d = 0; d < 10; ++d) {
    --b[p][d][old%10];
    old /= 10;
  }
  for(int d = 0; d < 10; ++d) {
    ++b[p][d][y%10];
    y /= 10;
  }
}

int query(int l, int r, int d, int c) {
  --d;
  int p = pos[l], q = pos[r], res = 0;
  if(p == q) 
    for(int i = l; i <= r; ++i) res += getres(a[i], d, c);
  else {
    for(int i = p+1; i < q; ++i) res += b[i][d][c];
    for(int i = l; i <= ed[p]; ++i) res += getres(a[i], d, c);
    for(int i = st[q]; i <= r; ++i) res += getres(a[i], d, c);
  }
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  init(1, n);
  while(m--) {
    char ch; cin >> ch;
    if(ch == 'Q') {
      int l, r, d, c; cin >> l >> r >> d >> c;
      cout << query(l, r, d, c) << endl;
    } else {
      int x, y; cin >> x >> y;
      change(x, y);
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  dv[0] = 1;
  for(int i = 1; i < 10; ++i) dv[i] = dv[i-1]*10;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}