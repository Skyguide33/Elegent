//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

ll fp(ll b, ll p) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> dp(n+1, 0);
  dp[0] = 1;
  for(int i = 1; i <= min(n, k); ++i) dp[i] = dp[i-1]*26%MOD;
  if(k+1 <= n) dp[k+1] = (dp[k]*26-fp(5, k+1)+MOD)%MOD;
  for(int i = k+2; i <= n; ++i) {
    dp[i] = (dp[i-1]*26-fp(5, k+1)*21%MOD*dp[i-k-2]%MOD+MOD)%MOD;
  }
  cout << dp[n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}