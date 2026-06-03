//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int x, y; cin >> x >> y;
  if(x%2 && y%2) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}