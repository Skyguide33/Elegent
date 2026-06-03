//2026/4/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll n, x, y; cin >> n >> x >> y;
  if(x <= y) cout << y-x+1 << endl;
  else cout << 0 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}