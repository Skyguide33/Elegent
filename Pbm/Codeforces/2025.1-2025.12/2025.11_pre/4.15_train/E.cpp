//2025/4/
#include <bits/stdc++.h>
using namespace std;

struct Seg {
  int l, r;
} seg[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n, s, m; cin >> n >> s >> m;
    for(int i = 1; i <= n; i++) cin >> seg[i].l >> seg[i].r;
    if(seg[1].l >= s || seg[n].r + s <= m) {
      cout << "YES" << endl;
      continue;
    } else {
      bool flag = 0;
      for(int i = 1; i < n; i++) {
        if(seg[i+1].l - seg[i].r >= s) {
          cout << "YES" << endl;
          flag = 1;
          break;
        }
      }
      if(flag) continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}