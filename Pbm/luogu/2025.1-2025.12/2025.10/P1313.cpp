//2025/10/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 10007

int fast_power(int b, int p) {
  int res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

int c[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a, b, k, n, m; cin >> a >> b >> k >> n >> m;
  a %= MOD; b %= MOD;
  int ans = (fast_power(a, n)*fast_power(b, m))%MOD;
  for(int i = 0; i <= k; ++i) {
    c[i][0] = c[i][i] = 1;
    for(int j = 1; j < i; ++j) c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
  }
  // for(int i = 0; i <= k; ++i) {
  //   for(int j = 0; j <= i; ++j) cout << c[i][j] << ' ';
  //   cout << endl;
  // }
  ans = ans*c[k][m]%MOD;
  cout << ans << endl;
  return 0;
}