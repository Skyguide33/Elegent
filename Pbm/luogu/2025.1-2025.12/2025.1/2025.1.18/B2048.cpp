//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int x, fee = 8;
  char c;
  cin >> x >> c;
  fee += (c=='y'?5:0);
  fee += (x>1000?ceil((x-1000)/500.)*4:0);
  cout << fee << endl;
  return 0;
}