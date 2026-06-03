//2025/8/26
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  for(int tt = 1; tt <= T; ++tt) {
    int n, a, b; cin >> n >> a >> b;
    cout << "Case #" << tt << ": " << (n/gcd(a, b)%2? "Yuwgna": "Iaka") << endl;
  }
  return 0;
}
