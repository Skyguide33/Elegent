//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (!(n%3)&&!(n%5)?"YES":"NO") << endl;
  return 0;
}