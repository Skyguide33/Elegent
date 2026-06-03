//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n+1, vector<int>(m+1));
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> a[i][j];
  }
  int ans = 0;
  for(int l = 1; l <= n; ++l) {
    for(int u = 1;  u <= m; ++u) {
      for(int r = l; r <= n; ++r) {
        for(int d = u; d <= m; ++d) {
          set<int> c;
          bool flag = 1;
          for(int i = l; i <= r; ++i) {
            for(int j = u; j <= d; ++j) {
              if(!c.count(a[i][j])) c.insert(a[i][j]);
              else flag = 0;
            }
          }
          ans += flag;
        }
      }
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