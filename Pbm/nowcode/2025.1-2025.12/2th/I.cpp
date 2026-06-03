//2025/9/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int x, y; cin >> x >> y;
    if(x == 1 || y == 1) cout << -1 << endl;
    else cout << 1 << endl;
  }
  return 0;
}