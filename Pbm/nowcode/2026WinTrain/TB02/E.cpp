//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1005][1005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    if(i%2) {
      for(int j = 1; j <= n-i; ++j) a[i][j] = 1;
    } else {
      for(int j = 1; j <= n-i; ++j) a[n-j+1][n-i+1] = 1;
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) cout << a[i][j];
    cout << endl;
  }
  return 0;
}