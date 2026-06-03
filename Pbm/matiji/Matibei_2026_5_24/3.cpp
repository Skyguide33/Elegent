//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int g[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, t1, t2; cin >> n >> m >> t1 >> t2;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  int row = n/t1, col = m/t2;
  int ans = 0;
  for(int i = 0; i < row; ++i) {
    for(int j = 0; j < col; ++j) {
      int x = 0;
      for(int k = 0; k < t1; ++k) {
        for(int l = 0; l < t2; ++l) {
          x ^= g[i*t1+k][j*t2+l];
        }
      }
      ans += x;
    }
  }
  cout << ans << endl;
  return 0;
}