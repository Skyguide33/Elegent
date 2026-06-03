//2026/1/2 补题
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll MOD = 998244353;

int c[51][51], f[51], a[51];

void solve() {
  int n; cin >> n;
  int sum = 0;
  for(int i = 0; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int k = sum/n;
  int ned = 0, cnt = 0;
  bool flag = 1;
  for(int i = 1; i <= n; ++i) {
    int r = k-a[i];
    if(r >= 0) {
      ned += r;
      ++cnt;
    } else if(r < -1) {
      flag = 0;
      break;
    }
  }
  if(!flag || ned > a[0]) {
    cout << 0 << endl;
    return;
  }
  a[0] -= ned;
  int x = cnt-a[0];
  cout << 1ll*c[cnt][x]*f[x]%MOD*f[n-x]%MOD << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  f[0] = 1;
  for(int i = 1; i <= 50; ++i) f[i] = 1ll*f[i-1]*i%MOD;
  for(int i = 0; i <= 50; ++i) {
    c[i][0] = c[i][i] = 1;
    for(int j = 1; j < i; ++j) {
      c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
    }
  }
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}