//2025/4/5
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int x[3]; cin >> x[0] >> x[1] >> x[2];
    sort(x, x+3);
    int ans = 1e9;
    ans = min(ans, x[1]+x[2]-2*x[0]);
    ans = min(ans, x[2]-x[0]);
    ans = min(ans, 2*x[2]-x[0]-x[1]);
    cout << ans << endl;
  }
  return 0;
}