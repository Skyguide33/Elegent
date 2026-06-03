//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Pair {
  int c, l, r;
} b[105];

void solve() {
  int n, k, q; cin >> n >> k >> q;
  for(int i = 1; i <= q; ++i) cin >> b[i].c >> b[i].l >> b[i].r;
  sort(b+1, b+q+1, [&] (const Pair &x, const Pair &y) {
    if(x.c == y.c) {
      if(x.l == y.l) return x.r < y.r;
      return x.l < y.l;
    }
    return x.c < y.c;
  });
  vector<int> a(n+1, -1);
  for(int i = 1; i <= q; ++i) {
    // cout << "b[i].c=" << b[i].c << endl;
    if(b[i].c == 1) {
      for(int j = b[i].l; j <= b[i].r; ++j) {
        if(a[j] < k) a[j] = k;
      }
    } else {
      for(int j = b[i].l; j <= b[i].r; ++j) {
        if(a[j] == k) a[j] = k+1;
      }
      set<int> st;
      for(int j = b[i].l; j <= b[i].r; ++j) {
        if(a[j] >= 0) st.insert(a[j]);
      }
      int add1 = 0;
      for(int j = b[i].l; j <= b[i].r; ++j) {
        if(a[j] == -1) {
          while(st.count(add1)) ++add1;
          if(add1 == k) break;
          a[j] = add1;
          st.insert(add1);
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i] == -1) a[i] = 0;
    cout << a[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}