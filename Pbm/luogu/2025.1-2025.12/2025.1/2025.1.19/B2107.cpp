//2025/1/19
#include <iostream>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  int a[r][c];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  for(int j = 0; j < c; j++) {
    for(int i = r-1; i >= 0; i--) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}