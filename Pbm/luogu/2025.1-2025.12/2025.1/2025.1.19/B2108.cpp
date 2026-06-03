//2025/1/19
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  int a[r][c], b[r][c];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(i == 0 || i == r-1 || j == 0 || j == c-1) {
        b[i][j] = a[i][j];
      } else {
        b[i][j] = round((a[i][j] + a[i][j-1] + a[i][j+1] + a[i+1][j] + a[i-1][j]) / 5.);  
      }
      cout << b[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}