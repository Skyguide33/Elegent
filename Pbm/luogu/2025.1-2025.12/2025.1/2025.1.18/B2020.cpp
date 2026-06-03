//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {
  int a, b, c, d, e, n;
  cin >> a >> b >> c >> d >> e;
  n = a + b + c + d + e;
  a /= 3;
  e += a;
  b += a;
  b /= 3;
  a += b;
  c += b;
  c /= 3;
  b += c;
  d += c;
  d /= 3;
  e += d;
  c += d;
  e /= 3;
  d += e;
  a += e;
  cout << format("{} {} {} {} {}\n{}", a, b, c, d, e, n-a-b-c-d-e);
  return 0;
}