//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int a, b; cin >> a >> b;
  if(b == 9) {
    if(a%2) cout << 10 << ' ' << 11 << endl;
    else cout << 1 << ' ' << 11 << endl;
  } else if(b == 0) {
    if(a == 1) cout << 1 << ' ' << 100 << endl;
    else cout << 1 << ' ' << 10 << endl;
  } else {
    int x = b, y = 9;
    int gd = gcd(x, y);
    cout << x/gd << ' ' << y/gd << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}