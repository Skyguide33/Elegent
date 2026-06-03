//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if(y > x) x = y;
  if(z > x) x = z;
  cout << x << endl;
  return 0;
}