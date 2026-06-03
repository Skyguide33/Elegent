//2026/2/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[200005];



int inv(int n) {
  int b = n, p = MOD-2, res = 1;
  while(p) {
    if(p&1) res = 1ll*res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int lcm = a[1];
  for(int i = 2; i <= n; ++i) {
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}