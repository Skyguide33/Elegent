//2026/6/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000000

int dp[305][305];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n = s.length();
  s = ' '+s;
  for(int i = 1; i <= n; ++i) dp[i][i] = 1;
  for(int len = 2; len <= n; ++len) {
    for(int l = 1; l+len-1 <= n; ++l) {
      int r = l+len-1;
      if(s[l] == s[r]) {
        dp[l][r] = dp[l+1][r-1];
        for(int k = l+2; k <= r-2; k += 2) {
          if(s[k] == s[l]) {
            dp[l][r] = (dp[l][r]+1ll*dp[l][k]*dp[k+1][r-1]%MOD)%MOD;
          }
        }
        // cout << format("dp[{}][{}]={}", l, r, dp[l][r]) << endl;
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = i; j <= n; ++j) {
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}