//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int a[51], dp[51][3];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n = s.length();
  for(int i = 1; i <= n; ++i) {
    a[i] = s[i-1]-'0';
  }
  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < 3; ++j) {
      dp[i][(j+a[i])%3] = (dp[i-1][(j+a[i])%3]+dp[i-1][j])%MOD;
    }
  }
  cout << dp[n][0]-1 << endl;
  return 0;
}