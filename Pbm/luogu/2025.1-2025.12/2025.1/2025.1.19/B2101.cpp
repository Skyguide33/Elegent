//2025/1/19
#include <iostream>
using namespace std;

int main() {
  int r, c, ans = 0;
  cin >> r >> c;
  int a[r][c];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> a[i][j];
      if(i == 0 || i == r-1 || j == 0 || j == c-1) {
        ans += a[i][j];
      }
    }
  }
  cout << ans;
  return 0;
}