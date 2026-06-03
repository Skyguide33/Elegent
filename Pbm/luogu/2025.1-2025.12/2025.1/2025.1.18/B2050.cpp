//2025/1/18
#include <iostream>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  if(a+b>c&&b+c>a&&a+c>b) cout << 1;
  else cout << 0;
  return 0;
}