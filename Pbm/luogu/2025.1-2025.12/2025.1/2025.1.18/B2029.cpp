//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float h, r;
  cin >> h >> r;
  cout << ceil(20000/(3.14*r*r*h)) << endl;
  return 0;
}