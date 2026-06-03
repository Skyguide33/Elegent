//2025/6/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll n0[100005], n1[100005], dp[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  n0[1] = n1[2] = 1;
  for(int i = 3; i <= 100000; ++i) {
    n0[i] = (n0[i-2]+n0[i-1]) % MOD;
    n1[i] = (n1[i-2]+n1[i-1]) % MOD;
  }
  for(int i = 3; i <= 100000; ++i) {
    dp[i] = ((dp[i-2]+dp[i-1])%MOD + (n1[i-2]*n0[i-1])%MOD) % MOD;
  }
  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    cout << dp[n] << endl;
  }
  return 0;
}