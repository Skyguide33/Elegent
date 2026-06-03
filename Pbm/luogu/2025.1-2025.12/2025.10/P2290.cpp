//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cnt[151];
ll f[151];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  f[0] = 1;
  for(int i = 1; f[i-1] <= 1e17; ++i) {
    f[i] = f[i-1]*i;
  }
  int n, sum = 0; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int t; cin >> t;
    ++cnt[t]; sum += t;
  }
  if(sum != 2*(n-1)) cout << 0 << endl;
  else {
    ll ans = 1;
    for(int i = 1; i <= n-1; ++i) {
      ans *= f[cnt[i]];
    }
    cout << ans << endl;
  }
  return 0;
}