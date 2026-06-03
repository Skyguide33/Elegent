//2025/1/18
#include <iostream>
#include <format>
using namespace std;

int main() {  
  double n;
  int a = 3;
  // scanf("%lf", &n);
  // printf("%.3f", n);

  // cin >> n;
  // cout << fixed;
  // cout.precision(3);
  // cout << n;

  cin >> n;
  cout << format("{:.{}f}", n, a);
  return 0;
}