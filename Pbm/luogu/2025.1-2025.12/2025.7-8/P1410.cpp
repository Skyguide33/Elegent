//2025/8/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[2005], dp[2005][1005];

void solve() {
  int n; 
  while(cin >> n) {
    for(int i = 1; i <= n; ++i) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 2; i <= n; ++i) {
      for(int j = 2; j <= i; ++j) {
        if(a[i-1] < a[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        //if(dp[i-1][i-j] < a[i]) dp[i][j] = min(dp[i][j], a[i-1]); 
        if(dp[i-1][j-1] < a[i]) dp[i][i-j+1] = min(dp[i][i-j+1], a[i-1]);
      }
    }
    if(dp[n][n/2] <= 1000000000) cout << "Yes!" << endl;
    else cout << "No!" << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}