//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n; cin >> n;
  int ans, t; cin >> ans;
  while(--n) {
    cin >> t;
    ans = __gcd(ans, t);
  }
  cout << abs(ans) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}