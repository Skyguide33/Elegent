//2025/6/6
#include <bits/stdc++.h>
using namespace std;

int n, m, q[17][100001];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> q[0][i];
  for(int i = 1; (1<<i) <= n; ++i) {
    for(int j = 1; j+(1<<i) <= n+1; ++j) { 
      q[i][j] = min(q[i-1][j], q[i-1][j+(1<<(i-1))]);
    }
  }
  for(int i = 1; i <= n-m+1; ++i) {
    int logm = log2(m);
    cout << min(q[logm][i], q[logm][i+m-(1<<logm)]) << endl;
  }
  return 0;
}