#include <iostream>
using namespace std;

int main() {
  int n = 2024, ans = 0;
  while(n--) {
    ans++;
    while(ans % 2 == 0 || ans % 11 == 0 || ans % 23 == 0) ans++;
    cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}