//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

ll dp[1000005], sum[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, d; cin >> n >> d;
  if(d == 1) {
    ll ans = 1;
    for(int i = 1; i <= 2*n; ++i) ans = ans*2%MOD;
    cout << ans << endl;
  } else {
    for(int i = 1; i < d; ++i) {
      dp[i] = 1;
      sum[i] = sum[i-1]+2;
    }
    for(int i = d; i <= n; ++i) {
      dp[i] = (1+sum[i-d]+dp[i-d+1])%MOD;
      sum[i] = (sum[i-1]+2*dp[i])%MOD;
    }
    cout << sum[n]+1 << endl;
  }
  return 0;
}