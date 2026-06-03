//2025/6/13
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a = 3980900, b = 6803720, c = 4053280;
  int Gcd = __gcd(a, __gcd(b, c));
  a /= Gcd, b /= Gcd, c /= Gcd;
  cout << a << "," << b << "," << c << endl;
  return 0;
}