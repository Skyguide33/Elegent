//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int n, num, max = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> num;
    if(num > max) max = num;
  }
  cout << max;
  return 0;
}