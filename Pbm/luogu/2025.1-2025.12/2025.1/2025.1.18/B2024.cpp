//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {
  double n;
  // scanf("%lf", &n);
  // printf("%lf\n%.5lf\n%e\n%g", n, n, n, n);

  // cin >> n;
  // cout << fixed;
  // cout << n << endl;
  // cout.precision(5);
  // cout << n << endl;
  // cout << scientific;
  // cout.precision(6);
  // cout << n << endl;
  // cout << defaultfloat;
  // cout << n << endl;

  cin >> n;
  cout << format("{0:f}\n{0:.5f}\n{0:e}\n{0:g}\n", n);
  return 0;
}

