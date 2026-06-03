//2025/2/15
#include <iostream>
using namespace std;
  
int year[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
  int ans = 0, yy, mm, dd;
  for(yy = 2000; yy < 2000000; yy++) {
    for(mm = 1; mm <= 12; mm++) {
      if(yy % mm == 0) {
        for(dd = 1; dd <= year[mm]; dd++) {
          if(yy % dd == 0) ans++;
        }
        if(mm == 2 && ((yy % 4 == 0 && yy % 100) || yy % 400 == 0)) {
          if(yy % 29 == 0) ans++;
        }
      }
    }
  }
  cout << ans+1 << endl;
  return 0;
}