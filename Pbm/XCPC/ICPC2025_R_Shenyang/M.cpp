//2026/3/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double a[9], b[9], r[4][9];
int c[9];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 8; ++i) cin >> a[i] >> b[i], c[i] = i;
  bool flag = 1;
  double ans = 0.0;
  for(int i = 1; i <= 8; ++i) r[0][i] = 1.0; 
  while(flag) {
    for(int i = 1; i <= 3; ++i) {
      for(int j = 1; j <= 8; ++j) r[i][j] = 0.0;
    }
    for(int i = 1; i <= 3; ++i) {
      for(int j = 1; j <= 8; j += (1<<i)) {
        for(int k = 0; k < (1<<(i-1)); ++k) {
          for(int l = (1<<(i-1)); l < (1<<i); ++l) {
            double base = r[i-1][j+k]*r[i-1][j+l];
            double lw = a[c[j+k]], rw = b[c[j+l]], lrw = lw+rw;
            r[i][j+k] += lw/lrw*base;
            r[i][j+l] += rw/lrw*base;
          }
        }
      }
    }
    for(int i = 1; i <= 8; ++i) {
      if(c[i] == 1) {
        ans = max(ans, r[3][i]);
        break;
      }
    }
    flag = next_permutation(c+1, c+9);
  }
  cout << setprecision(8) << fixed << ans << endl;
  return 0;
}