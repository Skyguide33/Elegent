//2025/1/18
#include <iostream>
using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  cout << a - (int(a/b)* b) << endl;
  return 0;
}