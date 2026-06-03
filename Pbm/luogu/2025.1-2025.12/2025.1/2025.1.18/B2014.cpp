//2025/1/18
#include <iostream>
using namespace std;
#define PI 3.14159


int main() {
  double r;
  cin >> r;
  cout << fixed;
  cout.precision(4);
  cout << 2 * r << ' ' << 2 * PI * r << ' ' << PI * r * r << endl;
  return 0;
}

