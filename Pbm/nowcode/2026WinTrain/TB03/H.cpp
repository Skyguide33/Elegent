//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
  if(ya == yb) {
    if(abs(ya*(xa-xb)) == 4) cout << 0 << endl;
    else cout << "no answer" << endl;
    return 0;
  }
  double x1 = xa, x2 = xb, y1 = ya, y2 = yb;
  double y = abs(y1-y2);
  double xx = -y2*(x1-x2)/(y1-y2)+x2;
  cout << setprecision(8) << fixed << 4./y+xx << endl;
  return 0;
}