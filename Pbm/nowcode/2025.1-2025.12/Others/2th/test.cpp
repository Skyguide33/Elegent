//2025/7/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265358979323846

struct Point{
  double x, y;
} p;


double getangle(Point a) {
  double a_angle = 0;
  if(a.x == 0) {
    if(a.y > 0) a_angle = PI/2;
    else if(a.y < 0) a_angle = PI*3/2;
  } else if(a.x > 0) {
    a_angle = atan(a.y/a.x);
    if(a_angle < 0) a_angle += 2*PI;
  } else {
    if(a.y >= 0) a_angle = atan(a.y/a.x) + PI;
    else  a_angle = atan(a.y/a.x) + PI;
  }
  return a_angle;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout.precision(7);
  cout << fixed << getangle({-3, -4}) << endl;
  cout << fixed << getangle({1, -2}) << endl;
  cout << fixed << getangle({1, 0}) << endl;
  cout << fixed << getangle({-1, 0}) << endl;
  cout << fixed << getangle({0, 1}) << endl;
  cout << fixed << getangle({0, -1}) << endl;
  return 0;
}