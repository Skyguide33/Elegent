//2026/3/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll m1, m2, m3, x, y; cin >> m1 >> m2 >> m3 >> x >> y;
  while(m2 >= y || m3 >= x) {
    // cout << m1 << ' ' << m2 << ' ' << m3 << ' ' << x << ' ' << y << endl;
    m2 += m3/x;
    m3 %= x;
    m1 += m2/y;
    m3 += m2/y;
    m2 %= y;
  }
  cout << m1 << endl;
  return 0;
}