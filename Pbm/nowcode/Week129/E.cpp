//2026/2/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'
#define MOD 1000000007

int f[200005], f_inv[200005];

int fp(int b, int p) {
  int res = 1;
  while(p) {
    if(p&1) res = 1ll*res*b%MOD;
    b = 1ll*b*b%MOD;
    p >>= 1;
  }
  return res;
}

int inv(int n) {
  return fp(n, MOD-2);
}

int C(int n, int k) {
  return 1ll*f[n]*inv(f[n-k])%MOD*inv(f[k])%MOD;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  f[0] = 1;
  for(int i = 1; i <= n; ++i) f[i] = 1ll*f[i-1]*i%MOD;
  for(int i = 1; i <= n; ++i) f_inv[i] = inv(f[i]);
  for(int i = 1; i <= n; ++i) {
    cout << 1ll*C(n, i)*fp(2, n-1)%MOD << ' ';
  }
  cout << endl;
  return 0;
}