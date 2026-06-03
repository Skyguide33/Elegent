//2025/9/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  ++n, ++m;
  vector<vector<ll>> ans(n+1, vector<ll>(m+1));
  for(int a = 0; a < min(n, m); ++a) {
    for(int b = 1; a+b < min(n, m); ++b) {
      auto work = [&] (int u, int l) {
        int r = m-a-b+l, d = n-a-b+u; 
        ++ans[u][l];
        --ans[u][r];
        --ans[d][l];
        ++ans[d][r];
      };
      work(0, b);
      work(a, 0);
      work(b, a+b);
      work(a+b, a);
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(i) ans[i][j] += ans[i-1][j];
      if(j) ans[i][j] += ans[i][j-1];
      if(i && j) ans[i][j] -= ans[i-1][j-1];
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}