//2025/7/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct casino {
  int l, r, real;
} a[100005];

bool cmp(casino x, casino y) { return x.l < y.l; }

void solve() {
  int n, x; cin >> n >> x;
  for(int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r >> a[i].real;
  sort(a+1, a+n+1, cmp);
  if(x < a[1].l) cout << x << endl;
  else {
    for(int i = 1; i <= n; ++i) {
      if(x >= a[i].l && x <= a[i].r) x = max(x, a[i].real); 
    }
    cout << x << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}