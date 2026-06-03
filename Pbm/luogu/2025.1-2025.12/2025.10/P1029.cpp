//2025/10/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int x, y; cin >> x >> y;
  if(y%x) cout << 0 << endl;
  else if(x == y) cout << 1 << endl;
  else {
    int ab = y/x, ans = 1, t = sqrt(ab);
    for(int i = 2; i <= t; ++i) {
      if(ab%i == 0 && gcd(ab/i, i) == 1) ++ans;
    }
    cout << ans*2 << endl;
  }
  return 0;
}