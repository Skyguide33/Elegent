//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll r; cin >> r;
  ll ans = 0;
  ll b = 1;
  while(r) {
    ans += r%10*b;
    r /= 10;
    b *= 2;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}