//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int c[101][101];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    for(int j = i+1; j <= n; ++j) cin >> c[i][j];
  }
  bool flag = 0;
  for(int i = 2; i < n; ++i) {
    for(int j = 1; j < i; ++j) {
      for(int k = i+1; k <= n; ++k) {
        if(c[j][i]+c[i][k] < c[j][k]) {
          flag = 1;
          break;
        }
      }
    }
  }
  cout << (flag? "Yes": "No") << endl;
  return 0;
}