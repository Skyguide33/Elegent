//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int d;
  double wt = 0, bt = 50;
  cin >> d;
  wt += d/1.2;
  bt += d/3.;
  if(wt<bt) cout << "Walk";
  else if(wt>bt) cout << "Bike";
  else cout << "All";
  return 0;
}