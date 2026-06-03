//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll s[1025], c[1025], scnt, dp[12][1025][83];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for(int i = 1; i < (1<<n); ++i) {
    if((i&(i<<1)) || (i&(i>>1))) continue; 
    s[++scnt] = i;
    int tt = i;
    while(tt) {
      c[scnt] += (tt&1);
      tt >>= 1;
    }
  }
  dp[0][0][0] = 1;
  for(int i = 1; i <= n+1; ++i) {
    for(int j = 0; j <= scnt; ++j) {
      for(int l = 0; l <= scnt; ++l) {
        if(s[j]&s[l] || (s[j]<<1)&s[l] || (s[j]>>1)&s[l]) continue;
        for(int p = c[j]; p <= k; ++p) {
          dp[i][j][p] += dp[i-1][l][p-c[j]];
        }
      }
    }
  }
  cout << dp[n+1][0][k] << endl;
  return 0;
}