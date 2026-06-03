//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a, b, c, x1, x2, delta;
  cin >> a >> b >> c;
  delta = b*b-4*a*c;
  if(delta >= 0) {
    x1 = (-b+sqrt(delta))/(2*a);
    x2 = (-b-sqrt(delta))/(2*a);
    cout.precision(5);
    cout << fixed;
    if(x1==x2) cout << "x1=x2=" << x1;
    else if(x1<x2) cout << "x1=" << x1 << ";x2=" << x2;
    else cout << "x1=" << x2 << ";x2=" << x1;
  }
  else cout << "No answer!";
  return 0;
}