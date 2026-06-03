//2026/2/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const double eps = 1e-8;

int sgn(double x) {
  if(fabs(x) < eps) return 0;
  else return x < 0? -1: 1;
}

double a[51][52];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n+1; ++j) cin >> a[i][j];
  }
  int flag = 0;
  for(int i = 1, col = 1; i <= n; ++i, ++col) {
    int row = i;
    while(col <= n && !sgn(a[row][col])) {
      while(row <= n && !sgn(a[row][col])) ++row;
      if(row <= n) break;
      else ++col, row = i;
    }
    if(col > n) {
      flag = 1;
      while(i <= n) {
        if(sgn(a[i][n+1])) {
          flag = 2;
          break;
        }
        ++i;
      }
      break;
    }
    if(row != i) {
      for(int j = col; j <= n+1; ++j) swap(a[row][j], a[i][j]); 
    }
    row = i;
    double div = a[row][col];
    for(int j = col; j <= n+1; ++j) a[row][j] /= div;
    for(int j = 1; j <= n; ++j) {
      if(j != row && sgn(a[j][col])) {
        double rate = a[j][col];
        for(int k = 1; k <= n+1; ++k) a[j][k] -= rate*a[row][k];
      }
    }
  }
  if(flag == 1) cout << "0" << endl;
  else if(flag == 2) cout << "-1" << endl;
  else {
    for(int i = 1; i <= n; ++i) {
      cout << format("x{0}={1:.2f}", i, a[i][n+1]) << endl;
    }
  } 
  return 0;
}