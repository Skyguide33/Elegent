//2025/1/18
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long n, num = 2, ans;
  cin >> n;
  while(n) {
    int i = 2;
    for(; i <= sqrt(num);i++) {
      if(num%i == 0) break;
    }
    if (i > sqrt(num)) {
      ans = num;
      n--;
    }
    num++;
  }
  cout << ans;
  return 0;
}