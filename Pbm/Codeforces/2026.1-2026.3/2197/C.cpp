//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll p, q; cin >> p >> q;
  ll x = 3*p-2*q;
  if(x >= 0 && x <= min(p, q-1)) cout << "Bob" << endl;
  else cout << "Alice" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}