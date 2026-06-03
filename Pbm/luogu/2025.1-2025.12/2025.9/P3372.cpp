//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[100005], sum[330], st[330], ed[330], pos[100005], add[330];
int block, t;

void build(int l, int r) {
  int n = r-l+1;
  block = sqrt(n);
  t = n/block;
  if(n%block) ++t;
  for(int i = 1; i <= t; ++i) {
    st[i] = (i-1)*block+l;
    ed[i] = i*block+l-1;
  }
  ed[t] = r;
  for(int i = l; i <= r; ++i) pos[i] = (i-l)/block+1;
  for(int i = 1; i <= t; ++i) {
    for(int j = st[i]; j <= ed[i]; ++j) {
      cin >> a[j];
      sum[i] += a[j];
    }
  }
}

void change(int L, int R, ll d) {
  int p = pos[L], q = pos[R];
  if(p == q) {
    for(int i = L; i <= R; ++i) a[i] += d;
    sum[p] += (R-L+1)*d;
  } else {
    for(int i = p+1; i < q; ++i) add[i] += d;
    for(int i = L; i <= ed[p]; ++i) a[i] += d;
    sum[p] += (ed[p]-L+1)*d;
    for(int i = st[q]; i <= R; ++i) a[i] += d;
    sum[q] += (R-st[q]+1)*d;
  }
}

ll query(int L, int R) {
  int p = pos[L], q = pos[R];
  ll ans = 0;
  if(p == q) {
    for(int i = L; i <= R; ++i) ans += a[i];
    ans += add[p]*(R-L+1);
  } else {
    for(int i = p+1; i < q; ++i) ans += sum[i]+add[i]*(ed[i]-st[i]+1);
    for(int i = L; i <= ed[p]; ++i) ans += a[i];
    ans += add[p]*(ed[p]-L+1);
    for(int i = st[q]; i <= R; ++i) ans += a[i];
    ans += add[q]*(R-st[q]+1);
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  build(1, n);
  while(m--) {
    ll op, x, y, k; cin >> op >> x >> y;
    if(op == 1) {
      cin >> k;
      change(x, y, k);
    } else cout << query(x, y) << endl;
  }
  return 0;
}
