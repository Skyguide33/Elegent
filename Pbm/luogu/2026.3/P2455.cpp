//2026/3/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 52
#define eps 1e-8

double a[N][N];

int Gauss(int n) {
  int c, r;
  for(c = 1, r = 1; c <= n; ++c) {
    int t = r; // 找列主元
    for(int i = r; i <= n; ++i) 
      if(fabs(a[i][c]) > fabs(a[t][c])) t = i;
    if(fabs(a[t][c]) < eps) continue;
    for(int j = c; j <= n+1; ++j) swap(a[t][j], a[r][j]); 
    for(int j = n+1; j >= c; j--) a[r][j] /= a[r][c]; // 将主元化为 1
    for(int i = 1; i <= n; ++i) 
      if(i != r && fabs(a[i][c]) > eps) 
        for(int j = n+1; j >= c; j--) a[i][j] -= a[r][j]*a[i][c];
    ++r;
  }
  if(r <= n) {
    for(int i = r; i <= n; ++i) 
      if(fabs(a[i][n+1]) > eps) return -1; // 无解
    return 0; // 无穷多解
  }
  return 1; // 唯一解
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) 
    for(int j = 1; j <= n+1; ++j) cin >> a[i][j];
  int res = Gauss(n);
  if(res == 1) {
    for(int i = 1; i <= n; ++i) 
      cout << format("x{}={:.2f}", i+1, a[i][n+1]) << endl;
  } else cout << res << endl;
  return 0;
}