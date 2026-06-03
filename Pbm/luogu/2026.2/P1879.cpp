//2026/2/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 100000000

int g[13], s[1<<12], cnt, dp[14][1<<12];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, n; cin >> m >> n;
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j) {
      char ch; cin >> ch;
      g[i] = (g[i]<<1)+ch-'0';
    }
  }
  for(int i = 0; i < (1<<n); ++i) {
    if(!(i&(i<<1))) s[cnt++] = i;
  }
  dp[0][0] = 1;
  for(int i = 1; i <= m+1; ++i) {
    for(int b = 0; b < cnt; ++b) {
      if((s[b]&g[i]) != s[b]) continue;
      for(int a = 0; a < cnt; ++a) {
        if(!(s[a]&s[b])) dp[i][b] = (dp[i][b]+dp[i-1][a])%MOD;
      }
    }
  }
  cout << dp[m+1][0] << endl;
  return 0;
}