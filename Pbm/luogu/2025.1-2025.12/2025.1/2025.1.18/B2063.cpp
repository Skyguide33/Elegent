//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x;
  int n;
  cin >> x >> n;
  cout.precision(4);
  cout << fixed << x*pow(1.001, n) << endl;
  return 0;
}