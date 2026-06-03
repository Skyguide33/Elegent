//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll f[300005], a[300005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> f[i];
  for(int i = 2; i <= n-1; ++i) {
    a[i] = (f[i+1]-2*f[i]+f[i-1])/2;
  }
  a[1] = f[n]; a[n] = f[1];
  for(int i = 2; i < n; ++i) a[1] -= (n-i)*a[i];
  a[1] /= n-1;
  for(int i = 2; i < n; ++i) a[n] -= (i-1)*a[i];
  a[n] /= n-1;
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}