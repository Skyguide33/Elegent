//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  ll ans = n, rst = n;
  while(rst >= k) {
    ll n_r = rst/k;
    ans += n_r;
    rst = rst%k+n_r;
  }
  cout << ans << endl;
  return 0;
}