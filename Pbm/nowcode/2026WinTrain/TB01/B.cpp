//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[200005], b[200005], f[200005];

bool cmp(int x, int y) { return x > y; }


void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  sort(a+1, a+n+1);
  sort(b+1, b+n+1);
  int lownum = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] > b[1]) {
      lownum = i-1;
      break;
    }
  }
  cout << 1ll*f[lownum]*f[n-lownum]%MOD << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  f[0] = 1;
  for(int i = 1; i <= 200000; ++i) f[i] = 1ll*f[i-1]*i%MOD;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}