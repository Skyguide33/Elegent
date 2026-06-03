#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double dx = 15, dy = 17, x = 343720, y = 233333;
  int xmpl = 1, ympl = 1;
  while(xmpl*x * dy != ympl*y * dx) {
    if(xmpl*x * dy > ympl*y * dx) ympl++;
    else xmpl++;
  }
    cout.precision(2);
    cout << fixed << 2 * sqrt(xmpl*xmpl*x*x + ympl*ympl*y*y) << endl;
  return 0;
}