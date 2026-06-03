//2025/3/21
#include <bits/stdc++.h>
using namespace std;

inline int dist(int ax, int ay, int bx, int by) {
  return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
} 

int main() {
  int bx, by, rx, ry;
  cin >> bx >> by >> rx >> ry;
  long long a[bx+1][by+1];
  memset(a, 0, sizeof(a));
  for(int i = 0; i <= bx; i++) {
    if((rx == i && ry == 0) || dist(rx, ry, i, 0) == 5) break;
    a[i][0] = 1;
  }
  for(int i = 0; i <= by; i++) {
    if((rx == 0 && ry == i) || dist(rx, ry, 0, i) == 5) break;
    a[0][i] = 1;
  }
  for(int i = 1; i <= bx; i++) {
    for(int j = 1; j <= by; j++) {
      if((rx == i && ry == j) || dist(rx, ry, i, j) == 5) continue;
      a[i][j] = a[i-1][j] + a[i][j-1];
    }
  }
  cout << a[bx][by] << endl;
  return 0;
}