//2026/4/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int x, y; cin >> x >> y;
  if(x > y || (x == 0 && y%2 == 0)) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  int add1 = x;
  if((y-x)%2) add1 += 1;
  y -= add1;
  int idx = 2;
  for(; idx <= add1+x; ++idx) cout << idx-1 << ' ' << idx << endl;
  for(; y; y -= 2, idx += 2) {
    cout << 1 << ' ' << idx << endl;
    cout << 1 << ' ' << idx+1 << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}