//2026/5/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[200005], f[200005];

ll fast_power(ll b, int p) {
  if(p < 0) return 0;
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    int l = i-1, r = n-i;
    ans = (ans+(((fast_power(3, l)+1)%MOD*fast_power(2, MOD-2))%MOD*a[i]%MOD*fast_power(2, r)))%MOD;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 200000; ++i) f[i] = (f[i-1]+i)%MOD;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}