//2025/9/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct req { int n, m; } q[10005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T, k; cin >> T >> k;
  int maxn = 0, maxm = 0;
  for(int i = 0; i < T; ++i) {
    cin >> q[i].n >> q[i].m;
    q[i].m = min(q[i].m, q[i].n);
    maxn = max(maxn, q[i].n);
    maxm = max(maxm, q[i].m);
  }
  vector<vector<int>> c(maxn+1, vector<int>(maxm+1, -1)), ans(maxn+1, vector<int>(maxm+1));
  c[0][0] = 1;
  for(int i = 1; i <= maxn; ++i) {
    c[i][0] = 1;
    if(maxm >= i) c[i][i] = 1;
    for(int j = 1; j <= maxm; ++j) {
      if(j < i) c[i][j] = (c[i-1][j]+c[i-1][j-1])%k;
      ans[i][j] = (!c[i][j])+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
    }
  }
  for(int i = 0; i < T; ++i) {
    cout << ans[q[i].n][q[i].m] << endl;
  }
  return 0;
}