//2025/2/8
#include <iostream>
using namespace std;

struct Point {
  int x, y;
};

int main() {
  int m, n;
  Point S;
  cin >> n >> m >> S.x >> S.y;
  Point M[m+1][n+1];
  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) cin >> M[i][j].x >> M[i][j].y;
  }
  cout << S.x << ' ' << S.y << endl;
  while(M[S.x][S.y].x != 0 && M[S.x][S.y].y != 0) {
    S = M[S.x][S.y];
    cout << S.x << ' ' << S.y << endl;
  }
  return 0;
}