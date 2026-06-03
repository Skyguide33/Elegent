//2025/4/15
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int x, y, k; cin >> x >> y >> k;
    int minx = x/k, miny = y/k;
    if(x % k) ++minx; if(y % k) ++miny;
    int ans = max(minx, miny) * 2;
    if(minx > miny) --ans;
    cout << ans << endl;
  }
  return 0;
}