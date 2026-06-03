//2026/3/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 52

ll a[N], n, k;

void gauss() {
  k = 1;
  for(int i = 62; i >= 0; --i) {
    for(int j = k; j <= n; ++j) 
      if((a[j]>>i)&1) swap(a[k], a[j]);
    if(!((a[k]>>i)&1)) continue;
    for(int j = 1; j <= n; ++j) 
      if(j != k && (a[j]>>i)&1) a[j] ^= a[k];
    if(k == n) break;
    ++k;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  gauss();
  ll ans = 0;
  for(int i = 1; i <= k; ++i) ans ^= a[i];
  cout << ans << endl;
  return 0;
}