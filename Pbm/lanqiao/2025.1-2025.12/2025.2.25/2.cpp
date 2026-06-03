#include <iostream>
using namespace std;

int main() {
  int ans = 2024;
  while(ans % 1024) {
    ans += 2024;
  }
  cout << ans << endl;
  return 0;
}