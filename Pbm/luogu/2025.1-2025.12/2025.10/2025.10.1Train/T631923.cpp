//2025/10/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m, x1, y1, x2, y2; cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  if(x1 == x2 && y1 == y2) cout << 0 << endl;
  else if(max(abs(x1-x2), abs(y1-y2)) == 1) cout << 1 << endl;
  else if(x1 == x2) {
    if((abs(y1-y2)%2 && abs(y1-y2) > max(x1-1, n-x1)) || (abs(y1-y2)%2 == 0 && abs(y1-y2)/2 > max(x1-1, n-x1))) cout << 3 << endl;
    else cout << 2 << endl;
  } else if(y1 == y2) {
    if((abs(x1-x2)%2 && abs(x1-x2) > max(y1-1, m-y1)) || (abs(x1-x2)%2 == 0 && abs(x1-x2)/2 > max(y1-1, m-y1))) cout << 3 << endl;
    else cout << 2 << endl;
  } else cout << 2 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}