//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

char s[102];
int dp[51][205][205];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int minp = 0, maxp = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> s[i];
    if(s[i] == 'L') --minp, --maxp;
    else if(s[i] == 'R') ++minp, ++maxp;
    else --minp, ++maxp;
  }
  for(int i = n+1; i <= 2*n; ++i) cin >> s[i];
  int ofs = 101;
  int ans = 0;
  for(int i = minp; i <= maxp; ++i) {
    if(i == 0) continue;
    dp[0][ofs+0][ofs+i] = 1;
    for(int j = 1; j <= n; ++j) {
      for(int k = -j; k <= j; ++k) {
        if(s[j] != 'L') {
          for(int l = i-j; l <= i+j; ++l) {
            if(k == l) continue;
            if(s[n+j] != 'L') {
              dp[j][ofs+k][ofs+l] = (dp[j][ofs+k][ofs+l]+dp[j-1][ofs+k-1][ofs+l-1])%MOD;
            }
            if(s[n+j] != 'R') {
              dp[j][ofs+k][ofs+l] = (dp[j][ofs+k][ofs+l]+dp[j-1][ofs+k-1][ofs+l+1])%MOD;
            }
          }
        }
        if(s[j] != 'R') {
          for(int l = i-j; l <= i+j; ++l) {
            if(k == l) continue;
            if(s[n+j] != 'L') {
              dp[j][ofs+k][ofs+l] = (dp[j][ofs+k][ofs+l]+dp[j-1][ofs+k+1][ofs+l-1])%MOD;
            }
            if(s[n+j] != 'R') {
              dp[j][ofs+k][ofs+l] = (dp[j][ofs+k][ofs+l]+dp[j-1][ofs+k+1][ofs+l+1])%MOD;
            }
          }
        }
      }
    }
    for(int j = i-n; j <= i+n; ++j) ans = (ans+dp[n][ofs+i][ofs+j])%MOD;
    for(int j = 0; j <= n; ++j) {
      for(int k = -j; k <= j; ++k) {
        fill(dp[j][ofs+k]+ofs+i-j, dp[j][ofs+k]+ofs+i+j+1, 0);
      }
    }
  }
  cout << ans << endl;
  return 0;
}