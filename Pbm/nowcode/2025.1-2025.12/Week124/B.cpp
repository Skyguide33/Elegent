//2025/12/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int ax, ay, bx, by, cx, cy; cin >> ax >> ay >> bx >> by >> cx >> cy;
  ll ab = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
  ll bc = (cx-bx)*(cx-bx)+(cy-by)*(cy-by);
  ll ac = (ax-cx)*(ax-cx)+(ay-cy)*(ay-cy);
  if(ab != bc || ab != ac) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}