//2025/1/18
#include <iostream>
using namespace std;

int main() {
  double sum = 0, a[10] = {28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
  int t;
  for(int i = 0; i < 10; i++) {
    cin >> t;
    sum += t*a[i];
  }
  cout.precision(1);
  cout << fixed << sum;
  return 0;
}