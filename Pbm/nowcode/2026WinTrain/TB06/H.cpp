//2026/2/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[2050], b[2050], dp[2050][2050];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 2048; ++j) {
      if(dp[i-1][j]) {
        dp[i][max(0, j-a[i])] = 1;
        dp[i][j^b[i]] = 1;
      }
    }
  }
  for(int i = 2047; i >= 0; --i) {
    if(dp[n][i]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}