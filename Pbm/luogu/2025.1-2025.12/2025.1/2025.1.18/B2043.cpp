//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(!(n%3)) cout << 3 << ' ';
  if(!(n%5)) cout << 5 << ' ';
  if(!(n%7)) cout << 7;
  else if(n%3 && n%5 && n%7) cout << 'n';
  return 0;
}