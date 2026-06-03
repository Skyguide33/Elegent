//2025/5/5
#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  while(m--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ++a[x1][y1]; ++a[x2+1][y2+1]; --a[x1][y2+1]; --a[x2+1][y1];
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      a[i][j] += a[i][j-1]+a[i-1][j]-a[i-1][j-1];
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}