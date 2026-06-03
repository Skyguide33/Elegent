//2025/11/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100][100];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 20; ++i) {
    a[i][1] = a[i][i] = 1;
    for(int j = 2; j < i; ++j) {
      a[i][j] = a[i-1][j-1]+a[i-1][j];
    }
  }
  for(int i = 1; i <= 20; ++i) {
    cout << i << "  ";
    for(int j = 1; j <= i; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}