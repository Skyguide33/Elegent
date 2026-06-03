//2025/1/18
#include <iostream>
using namespace std;

int main() {
  int m, n, num, count = 0;
  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    cin >> num;
    if(m >= num) m -= num;
    else count++;
  }
  cout << count;
  return 0;
}