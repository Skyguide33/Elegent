#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int ans = 0;
  for(int i = 2; i <= 2024; i++) {
    bool r = 2;
    for(int j = 2; j <= sqrt(i); j++) {
      if(i % j == 0) {
        r = 0;
        break;
      }
    }
    if(r) {
      if(2024 % i == 0) {
        cout << i << endl;
        ans += i;
      }
    }
  }
  cout << ans << endl;
}