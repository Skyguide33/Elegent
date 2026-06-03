//2025/4/15
#include <bits/stdc++.h>
using namespace std;

int num[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int l, r; cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; ++i) num[i] = i;
    while(num[l]) {
      num[l] /= 3;
      ans += 2;
    }
    for(int i = l+1; i <= r; ++i) {
      while(num[i]) {
        num[i] /= 3;
        ++ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}