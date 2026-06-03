//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

int inv(int b) {
  int res = 1, p = MOD-2;
  while(p) {
    if(p&1) res = 1ll*res*b%MOD;
    b = 1ll*b*b%MOD;
    p >>= 1;
  }
  return res;
}

int a[1000000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = n; i >= 1; --i) {
    a[i] = 1ll*n*inv(n-1)%MOD*i%MOD+1ll*i*(i-1)%MOD*inv(2*(n-1))%MOD;
    for(int j = i+1; j <= n; ++j) {
      a[i] = (a[i]+1ll*a[j]*inv(n-1))%MOD;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) ans = (ans+a[i])%MOD;
  ans = 1ll*ans*inv(n)%MOD;
  cout << ans << endl;
  return 0;
}