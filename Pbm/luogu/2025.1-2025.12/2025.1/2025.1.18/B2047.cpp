//2025/1/18
#include <iostream>
using namespace std;

int main() {
  double x;
  cin >> x;
  cout << fixed;
  cout.precision(3);
  if(x<5) cout << 2.5-x;
  else if(x >= 10) cout << x/2 - 1.5;
  else cout << 2-1.5*(x-3)*(x-3);
  return 0;
}