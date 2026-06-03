//2025/8/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  int e = a*d+b*c, f = b*d;
  int gd = gcd(e, f);
  cout << e/gd << ' ' << f/gd << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}