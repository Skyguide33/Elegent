//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {
  double n;
  // scanf("%lf", &n);
  // printf("%.12lf", n);

  // cin >> n;
  // cout << fixed;
  // cout.precision(12);
  // cout << n;

  cin >> n;
  cout << format("{:.12f}", n);
  return 0;
}