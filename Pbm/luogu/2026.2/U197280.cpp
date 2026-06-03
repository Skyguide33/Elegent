//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[1005][1005], p[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string a, b; cin >> a >> b;
  int n = a.length(), m = b.length();
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1]+1;
        p[i][j] = 0; // 左上角
      } else if(dp[i-1][j] > dp[i][j-1]) {
        dp[i][j] = dp[i-1][j];
        p[i][j] = 1; // 上边
      } else {
        dp[i][j] = dp[i][j-1];
        p[i][j] = 2; // 左边
      }
    }
  }
  string res;
  int i = n, j = m;
  while(i && j) {
    if(p[i][j] == 0) {
      res += a[i-1];
      --i; --j;
    } else if(p[i][j] == 1) --i;
    else --j;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
}