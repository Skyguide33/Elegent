//2025/5/24
#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  while(q--) {
    int l, r; cin >> l >> r;
    int minx = 0, maxx = r-l;
    while(minx < maxx) {
      int midx = minx + (maxx-minx) / 2;
      if(check(mid)) 
    }
  }
  return 0;
}