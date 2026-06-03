//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<vector<int>> a(n+2, vector<int>(n+2)), c(n+2, vector<int>(n+2));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      a[i][j] = (i-1)*n+j;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      c[i][j] = a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1];
      ans = max(ans, c[i][j]);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}