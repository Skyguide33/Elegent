//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double a[105][105], eps = 1e-7;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n+1; ++j) cin >> a[i][j];
  }
  for(int i = 1; i <= n; ++i) {
    int max = i;
    for(int j = i+1; j <= n; ++j) 
      if(fabs(a[j][i]) > fabs(a[max][i])) max = j;
    for(int j = 1; j <= n+1; ++j) swap(a[i][j], a[max][j]);
    if(fabs(a[i][i]) < eps) {
      cout << "No Solution" << endl;
      return 0;
    }
    for(int j = n+1; j >= 1; --j) a[i][j] /= a[i][i];
    for(int j = 1; j <= n; ++j) {
      if(j != i) {
        double temp = a[j][i]/a[i][i];
        for(int k = 1; k <= n+1; ++k) a[j][k] -= a[i][k]*temp;
      }
    }
    // cout.precision(2);
    // for(int k = 1; k <= n; ++k) {
    //   for(int l = 1; l <= n+1; ++l) {
    //     cout << fixed << a[k][l] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }
  cout.precision(2);
  for(int i = 1; i <= n; ++i) cout << fixed << a[i][n+1] << endl;
}