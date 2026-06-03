//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {
  char a;
  int b;
  float c;
  double d;
  
  // scanf("%c %d %f %lf", &a, &b, &c, &d);
  // printf("%c %d %.6f %.6lf", a, b, c, d);
  
  // cin >> a >> b >> c >> d;
  // cout << a << ' ' << b << ' ';
  // cout << fixed;
  // cout.precision(6);
  // cout << c << ' ';
  // cout << d;

  cin >> a >> b >> c >> d;
  cout << format("{0} {1} {2:.6f} {3:.6f}", a , b , c , d);
  return 0;
}