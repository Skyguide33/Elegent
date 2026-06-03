//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

char a[1005][1005];
int dp[1005][1005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      cin >> a[i][j]; dp[i][j] = 0;
    }
  }
  char mid = 0;
  if(a[1][1] == 'c') {
    if(a[n][n] == 'g') mid = 'd';
    else mid = 'g';
  } else if(a[1][1] == 'd') {
    if(a[n][n] == 'g') mid = 'c';
    else mid = 'g';
  } else {
    if(a[n][n] == 'c') mid = 'd';
    else mid = 'c';
  }
  int len = 2*n-1, s1 = len/3, s2 = len*2/3;
  dp[1][1] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(j+1 <= n && a[i][j+1] == (i+j <= s1? a[1][1]: (i+j <= s2? mid: a[n][n]))) 
        dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;
      if(i+1 <= n && a[i+1][j] == (i+j <= s1? a[1][1]: (i+j <= s2? mid: a[n][n]))) 
        dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;
    }
  }
  cout << dp[n][n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}