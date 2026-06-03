//2025/11/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  ll ans = 0;
  while(--n) {
    ll e, d; cin >> e >> d;
    ans += e*d;
  }
  cout << ans << endl;
  return 0;
}