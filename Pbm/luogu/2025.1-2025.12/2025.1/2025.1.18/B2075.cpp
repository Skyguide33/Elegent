//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int a, b, t;
  cin >> a >> b;
  a %= 1000;
  t = a;
  for(int i = 2; i <= b; i++) {
    t = (t*a)%1000;
  }
  if(t < 100 && t > 9) cout << '0' << t;
  else if(t < 10) cout << "00" << t;
  else cout << t;
  return 0;
}