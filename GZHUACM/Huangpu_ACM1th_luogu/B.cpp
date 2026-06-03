//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  if(n <= 5) cout << -1 << endl;
  else {
    if(n&1) cout << 3 << ' ' << n-3 << endl;
    else cout << 2 << ' ' << n-2 << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}