//2025/1/18
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double d(double x1, double y1, double x2, double y2) {
  double r = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
  return r;
}
int main() {
  double x1, y1, x2, y2, x3, y3, xmin, xmax, ymin, ymax;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a = d(x1,y1,x2,y2);
  double b = d(x1,y1,x3,y3);
  double c = d(x2,y2,x3,y3);
  cout.precision(2);
  cout << fixed << sqrt(4*pow(b*c,2)-pow(b*b+c*c-a*a,2))/4 << endl;
  return 0;
}