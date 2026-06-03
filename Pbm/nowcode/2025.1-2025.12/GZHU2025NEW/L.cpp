//2025/12/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[5005], dp[5005][5005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; 
    a[i] += a[i-1];
  }
  for(int i = 2; i <= n; ++i) {
    dp[i-1][i] = (a[i]-a[i-2])/2;
  }
  for(int i = 3; i <= n; ++i) {
    for(int j = 1; j+i-1 <= n; ++j) {
      dp[j][j+i-1] = max({(a[j+i-1]-a[j-1])/i, dp[j][j+i-2], dp[j+1][j+i-1]});
    }
  }
  ll ans = 0;
  for(int i = 2; i <= n; ++i) {
    for(int j = 1; j+i-1 <= n; ++j) ans += dp[j][j+i-1];
  }
  cout << ans << endl;
  return 0;
}