//2025/3/5 幸运数
#include <iostream>
using namespace std;

int main() {
  int ans = 0, t, count = 0;
  int sum[5][37] = {};  
  for(int i = 1; i < 10000; i++) {
    count = 0;
    t = i;
    while(t) {
      count += t%10;
      t /= 10;
    }
    if(i<=9) sum[1][count]++;
    else if(i <= 99) sum[2][count]++;
    else if(i <= 999) sum[3][count]++;
    else sum[4][count]++;
  }
  for(int i = 1; i <= 4; i++) {
    for(int j = 1; j <= i*9; j++) {
      for(int k = i; k >= 0; k--) {
        ans += sum[i][j]*sum[k][j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}