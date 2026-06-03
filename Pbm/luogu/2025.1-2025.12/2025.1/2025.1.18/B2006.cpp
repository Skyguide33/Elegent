//2025/1/18
#include <iostream>
using namespace std;

int main() {
  double x, y, ic;
  int a, b;
  cin >> x >> a >> y >> b;
  ic = (b*y - a*x) / (b - a);
  cout.precision(2);
  cout << fixed;
  cout << ic << endl;
  return 0;
}