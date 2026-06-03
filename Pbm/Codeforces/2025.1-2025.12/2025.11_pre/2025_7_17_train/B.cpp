//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, k; cin >> n >> k;
  int d = 0, ans = 0, t;
  while(n--) {
    cin >> t;
    if(t == 0) {
      if(d == k-1) {
        d = -1; ++ans;
      }
      else ++d;
    } else d = 0;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}