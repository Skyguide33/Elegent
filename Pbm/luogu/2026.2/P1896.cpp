//2026/2/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int s[520], c[520], cnt;
ll dp[11][520][82];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i = 0; i < (1<<n); ++i) {
    if((i&(i<<1)) == 0) {
      int tt = i;
      while(tt) {
        if(tt&1) ++c[cnt];
        tt >>= 1;
      }
      s[cnt++] = i;
    }
  }
  dp[0][0][0] = 1;
  for(int i = 1; i <= n+1; ++i) {
    for(int b = 0; b < cnt; ++b) {
      for(int a = 0; a < cnt; ++a) {
        if(s[a]&s[b] || s[a]&(s[b]<<1) || s[a]&(s[b]>>1)) continue;
        for(int l = c[a]+c[b]; l <= k; ++l) dp[i][b][l] += dp[i-1][a][l-c[b]];
      }
    }
  }
  cout << dp[n+1][0][k] << endl;
  return 0;
}