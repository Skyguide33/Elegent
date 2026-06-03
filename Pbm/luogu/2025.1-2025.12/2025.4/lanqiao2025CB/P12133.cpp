//2025/4/14
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    int a, b, c, k; cin >> a >> b >> c >> k;
    while(k--) {
      int na = (b+c)/2, nb = (a+c)/2, nc = (a+b)/2;
      a = na, b = nb, c = nc;
      if(a == b && b == c) break; 
    }
    cout << a << ' ' << b << ' ' << c << endl;
  }
  return 0;
}