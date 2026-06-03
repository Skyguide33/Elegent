//2025/1/18
#include <iostream>
using namespace std;

int main() {
  short a, b, c, count = 0;
  cin >> a >> b >> c;
  if(a>=60&&b>=60&&c>=60) cout << 0;
  else if((a<60&&b>=60&&c>=60)||(a>=60&&b<60&&c>=60)||(a>=60&&b>=60&&c<60)) cout << 1;
  else cout << 0;
  return 0;
}