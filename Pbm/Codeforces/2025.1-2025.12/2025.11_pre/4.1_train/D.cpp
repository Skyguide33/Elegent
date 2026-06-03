//2025/4/1
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    int x = 0, y = 0, miny = m;
    for(int i = 0; i < n; i++) {
      string a; cin >> a;
      int k = a.find('#');
      if(y == 0 && k != -1) y = k+1;
      if(k != -1 && k < miny) {
        miny = k;
        x = i+1;
      }
    }
    cout << x << ' ' << y << endl;
  }
  return 0;
}