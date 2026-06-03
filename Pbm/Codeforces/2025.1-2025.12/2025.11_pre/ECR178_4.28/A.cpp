//2025/4/28
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    if(sum % 3 == 0) {
      int avg = sum / 3;
      if((a < avg && b < avg) || (a == avg && b < avg) || (a < avg && b == avg)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else cout << "NO" << endl;
  }
  return 0;
}