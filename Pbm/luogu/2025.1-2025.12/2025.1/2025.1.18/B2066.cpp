//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n, num;
  double x, y, sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x >> y >> num;
    sum += (1.5*num + sqrt(x*x+y*y)/50.*2);
  }
  cout << int(ceil(sum));
  return 0;
}