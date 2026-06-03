//2026/2/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  int a, dp[3] = {0};
  for(int i = 1; i <= n; ++i) {
    cin >> a;
    dp[i%3] = max(dp[(i+1)%3]+a, dp[(i+2)%3]);
  }
  cout << dp[n%3] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}