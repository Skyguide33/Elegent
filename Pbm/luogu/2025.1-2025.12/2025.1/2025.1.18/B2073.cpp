//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  for(int i = 1; i <= n; i++) {
    while(a >= b) a -= b;
    a *= 10;
  }
  cout << a/b;
  return 0;
}