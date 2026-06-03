//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 998244353

int p[8], num_p[10], res_p[2027];

int inv(int n) {
  int res = 1, b = n%MOD, p = MOD-2;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

void solve() {
  int C; cin >> C;
  int p[8];
  for(int i = 1; i <= 7; ++i) cin >> p[i];
  int pw7_inv = inv((int)1e14%MOD);
  num_p[0] = (p[1]*p[2]*p[3]*p[5]*p[6]*p[7]*(100-p[4]))%MOD*pw7_inv%MOD;
  num_p[1] = (p[3]*p[6]*(100-p[1])*(100-p[2])*(100-p[4])*(100-p[5])*(100-p[7]))%MOD*pw7_inv%MOD;
  num_p[2] = (p[1]*p[3]*p[4]*p[5]*p[7]*(100-p[2])*(100-p[6]))%MOD*pw7_inv%MOD;
  num_p[3] = (p[1]*p[3]*p[4]*p[6]*p[7]*(100-p[2])*(100-p[5]))%MOD*pw7_inv%MOD;
  num_p[4] = (p[2]*p[3]*p[4]*p[6]*(100-p[1])*(100-p[5])*(100-p[7]))%MOD*pw7_inv%MOD;
  num_p[5] = (p[1]*p[2]*p[4]*p[6]*p[7]*(100-p[3])*(100-p[5]))%MOD*pw7_inv%MOD;
  num_p[6] = (p[1]*p[2]*p[4]*p[5]*p[6]*p[7]*(100-p[3]))%MOD*pw7_inv%MOD;
  num_p[7] = (p[1]*p[3]*p[6]*(100-p[2])*(100-p[4])*(100-p[5])*(100-p[7]))%MOD*pw7_inv%MOD;
  num_p[8] = (p[1]*p[2]*p[3]*p[4]*p[5]*p[6]*p[7])%MOD*pw7_inv%MOD;
  num_p[9] = (p[1]*p[2]*p[3]*p[4]*p[6]*p[7]*(100-p[5]))%MOD*pw7_inv%MOD;
  for(int i = 0; i <= 2026; ++i) {
    int tt = i;
    res_p[i] = 1;
    for(int j = 1; j <= 4; ++j) {
      res_p[i] = res_p[i]*num_p[tt%10]%MOD;
      tt /= 10;
    }
  }
  int ans = 0;
  for(int i = 0; i <= C; ++i) {
    ans = (ans+res_p[i]*res_p[C-i])%MOD;
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}