//2025/2/13
#include <iostream>
using namespace std;

int main() {
  int L, R, ans = 0, t;
  cin >> L >> R;
  for(int i = L; i <= R; i++) {
    t = i;
    while(t) {
      if(t % 10 == 2) ans++;
      t /= 10;
    }
  }
  cout << ans << endl;
  return 0;
}