//2026/5/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxt[20][200005], mint[20][200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    maxt[0][tt] = mint[0][tt] = i;
  }
  int lv = log2(n);
  for(int i = 1; i <= lv; ++i) {
    for(int j = 1; (j+(1<<i)-1) <= n; ++j) {
      maxt[i][j] = max(maxt[i-1][j], maxt[i-1][j+(1<<(i-1))]);
      mint[i][j] = min(mint[i-1][j], mint[i-1][j+(1<<(i-1))]);
    }
  }
  int ans = n;
  int logk = log2(k);
  for(int i = 1; i+k-1 <= n; ++i) {
    int maxn = max(maxt[logk][i], maxt[logk][i+k-(1<<logk)]);
    int minn = min(mint[logk][i], mint[logk][i+k-(1<<logk)]);
    ans = min(ans, maxn-minn);
  }
  cout << ans << endl;
  return 0;
}