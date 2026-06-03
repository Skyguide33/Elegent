//2025/11/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[21][21];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 20; ++i) {
    for(int j = 1; j <= 20; ++j) cin >> a[i][j];
  }
  int ans = 0;
  for(int i = 1; i <= 20; ++i) {
    for(int j = 1; j <= 17; ++j) {
      ans = max(ans, a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
    }
  }
  for(int j = 1; j <= 17; ++j) {
    for(int i = 1; i <= 17; ++i) {
      ans = max(ans, a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
    }
  }
  for(int i = 1; i <= 17; ++i) {
    for(int j = 1; j <= 17; ++j) {
      ans = max(ans, a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]);
    }
  }
  for(int i = 4; i <= 20; ++i) {
    for(int j = 1; j <= 17; ++j) {
      ans = max(ans, a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3]);
    }
  }
  cout << ans << endl;
  return 0;
}

// 70600674