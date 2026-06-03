#include <iostream>
using namespace std;

int main() {
  int n;
  double e = 2, t = 1;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    t /= i;
    e += t;
  }
  cout.precision(10);
  cout << fixed << e << endl;
  return 0;
}