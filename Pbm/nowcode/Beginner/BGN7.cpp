//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll x; cin >> x;
  if(x == 2 || x == 3 || x == 5 || x == 6 || x == 8 || x == 11 || x == 14) cout << "No" << endl;
  else cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}