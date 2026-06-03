//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int w, h, d; cin >> w >> h >> d;
  int n; cin >> n;
  int x = gcd(n, w);
  n /= x;
  int y = gcd(n, h);
  n /= y;
  int z = gcd(n, d);
  n /= z;
  if(n == 1) cout << x-1 << ' ' << y-1 << ' ' << z-1 << endl;
  else cout << -1 << endl;
  return 0;
}