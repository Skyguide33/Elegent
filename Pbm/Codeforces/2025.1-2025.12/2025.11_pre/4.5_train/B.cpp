//2025/4/5
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int x, y; cin >> x >> y;
    int ans = y / 2;
    y -= ans * 2;
    x -= ans * 7;
    if(y) {
      ++ans;
      x -= 11;
    }
    if(x > 0) {
      ans += (x-1) / 15 + 1;
    }
    cout << ans << endl;
  }
  return 0;
}