//2025/11/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll f[21], a[21], b[21];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, r; cin >> n >> r;
  f[0] = 1;
  for(int i = 1; i < n; ++i) f[i] = f[i-1]*i;
  --r;
  for(int i = 1; i <= n; ++i) {
    ll rr = r/f[n-i]+1; r %= f[n-i];
    for(int j = 1; j <= rr; ++j) {
      if(b[j]) ++rr;
    }
    a[i] = rr;
    b[a[i]] = 1;
    cout << a[i] << ' ';
  }
  cout << endl;
  return 0;
}