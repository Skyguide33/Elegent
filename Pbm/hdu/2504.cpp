//2025/8/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int a, b; cin >> a >> b;
  ll t = a*b;
  for(ll i = 2*b; i <= t; i += b) {
    if(gcd(a, i) == b) {
      cout << i << endl;
      return;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}