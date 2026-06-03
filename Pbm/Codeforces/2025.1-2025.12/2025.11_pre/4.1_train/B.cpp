//2025/4/1
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int x = 2, maxsx = 0, ans = 0;
    while(x <= n) {
      int t = (n/2)*(1+n/x);
      if(t >= maxsx) {
        maxsx = t;
        ans = x;
      }
      ++x;
    }
    cout << ans << endl;
  }
  return 0;
}