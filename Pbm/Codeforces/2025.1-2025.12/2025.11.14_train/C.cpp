//2025/11/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

ll a[200005];
ll dp[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i]; a[i] += a[i-1];
  }
  dp[0] = -1e18;
  for(ll i = 1; i <= n; ++i) {
    dp[i] = max(dp[i-1], i-i*i+a[i-1]);
  }
  ll maxnum = 0;
  for(ll i = 1; i <= n; ++i) {
    maxnum = max(maxnum, dp[i]-(a[i]-i*i-i));
  }
  cout << a[n]+maxnum << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}