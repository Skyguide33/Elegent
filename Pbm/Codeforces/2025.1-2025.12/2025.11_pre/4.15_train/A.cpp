//2025/4/15
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    string a; cin >> a;
    int ans = 0;
    for(auto& x: a) ans += x-'0';
    cout << ans << endl;
  }
  return 0;
}