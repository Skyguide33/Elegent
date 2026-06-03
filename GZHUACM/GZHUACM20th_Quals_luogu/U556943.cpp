//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll k, x, y; cin >> k >> x >> y;
  for(int i = 1; i < k; ++i) {
    y = (x+y)/2;
    if(y == x) break;
  }
  cout << y << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}