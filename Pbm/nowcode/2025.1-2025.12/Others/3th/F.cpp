//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, a, b; cin >> n >> a >> b;
  if(a >= n) {
    cout << "Sayonara\n";
    return;
  }
  n %= (a+b);
  if(n > a) cout << 0 << '\n';
  else cout << n << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}