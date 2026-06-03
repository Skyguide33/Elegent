//2025/7/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int x; cin >> x;
  int y = 9;
  while(x) {
    y = min(y, x - x/10*10);
    x /= 10;
  }
  cout << y << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}