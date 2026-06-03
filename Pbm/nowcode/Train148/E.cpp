//2026/1/23
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int a[1005], b[1005][1005], sum[1005][1005];

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    b[i][i] = a[i];
    for(int j = i+1; j <= n; ++j) {
      b[i][j] = min(b[i][j-1], a[j]);
    }
  }
  // for(int i = 1; i <= n; ++i) {
  //   for(int j = 1; j <= n; ++j) {
  //     cout << b[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // for(int i = 1; i <= n; ++i) {
  //   for(int j = 1; j <= n; ++j) {
  //     b[i][j] = b[i][j]+b[i][j-1]+b[i-1][j]-b[i-1][j-1];
  //     cout << b[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  for(int i = 1; i <= n; ++i) {
    for(int j = i; j <= n; ++j) sum[i][j] = b[j][j]-b[j][i-1]-b[i-1][j]+b[i-1][i-1];
  }
  while(m--) {
    int l, r; cin >> l >> r;
    int num = (r-l+2)*(r-l+1)/2;
    // cout << "num=" << num << ' ' << sum[l][r] << endl;
    cout << (sum[l][r]+num/2)/num << endl;
  }
  return 0;
}