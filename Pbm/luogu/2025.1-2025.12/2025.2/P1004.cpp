//2025/2/20
#include <iostream>
using namespace std;

inline int max(const int& a, const int& b) {
  if(a > b) return a;
  return b;
}
int main() {
  int N, x, y ,z, a[10][10] = {}, f[10][10][10][10] = {};
  cin >> N;
  do {
    cin >> x >> y >> z;
    a[x][y] = z;
  } while(x != 0);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= N; k++) {
        for(int l = 1; l <= N; l++) {
          f[i][j][k][l] = max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+a[i][j]+a[k][l];
          if(i == k && j == l) {
            f[i][j][k][l] -= a[i][j];
          }
        }
      }
    }
  }
  cout << f[N][N][N][N] << endl;
  return 0;
}