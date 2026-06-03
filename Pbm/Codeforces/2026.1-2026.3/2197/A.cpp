//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int d(int x) {
  int res = 0;
  while(x) {
    res += x%10;
    x /= 10;
  }
  return res;
}

void solve() {
  int x; cin >> x;
  int ans = 0;
  for(int y = x; y <= x+1000; ++y) {
    if(y-d(y) == x) ++ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}