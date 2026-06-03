//2025/1/19
#include <iostream>
using namespace std;

int main() {
  int a[6][6], b[6][6] = {0};
  for(int i = 1; i <= 5; i++) {
    int c = 1;
    for(int j = 1; j <= 5; j++) {
      cin >> a[i][j];
      if(a[i][c] < a[i][j]) c = j;
    }
    b[i][c] = 1;
  }
  for(int j = 1; j <= 5; j++) {
    int r = 1;
    for(int i = 1; i <= 5; i++) {
      if(a[r][j] > a[i][j]) r = i;
    }
    if(b[r][j] == 1) {
      cout << r << ' ' << j << ' ' << a[r][j] << endl;
      return 0;
    }
  }
  cout << "not found" << endl;
  return 0;
}