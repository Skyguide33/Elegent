//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[41][100001], num[41][41];

void solve() {
  memset(dp, 0x3f, sizeof(dp));
  memset(num, 0x3f, sizeof(num));
  string s; cin >> s;
  s = '0'+ s;
  int n; cin >> n;
  int len = s.length()-1;
  for(int i = 1; i <= len; ++i) {
    for(int j = i; j <= len; ++j) {
      num[i][j] = stoi(s.substr(i, j-i+1));
      if(num[i][j] > n) break;
    }
  }
  dp[0][0] = -1; int t;
  for(int i = 1; i <= len; ++i) {
    for(int j = 1; j <= n; ++j) {
      for(int k = 1; k <= i; ++k) {
        t = j-num[i-k+1][i];
        if(t >= 0) dp[i][j] = min(dp[i][j], dp[i-k][t]+1);
      }
    }
  }
  if(dp[len][n] > len) cout << -1 << '\n';
  else cout << dp[len][n] << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}