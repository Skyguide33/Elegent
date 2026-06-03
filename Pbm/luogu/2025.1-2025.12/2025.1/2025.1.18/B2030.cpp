//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  cout.precision(3);
  cout << fixed << sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) << endl;
  return 0;
}