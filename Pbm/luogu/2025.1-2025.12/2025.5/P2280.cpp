//2025/5/5
#include <bits/stdc++.h>
using namespace std;

int a[5005][5005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  while(n--) {
    int x, y, v; cin >> x >> y >> v;
    a[x+1][y+1] += v;
  }
  for(int i = 1; i <= 5001; ++i) {
    for(int j = 1; j <= 5001; ++j) {
      a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
  }
  int ans = 0;
  for(int i = m; i <= 5001; ++i) {
    for(int j = m; j <= 5001; ++j) {
      ans = max(ans, a[i][j]-a[i-m][j]-a[i][j-m]+a[i-m][j-m]);
    }
  }
  cout << ans << endl;
  return 0;
}