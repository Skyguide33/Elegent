//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[4][4], cnt[10], row[4], col[4];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 3; ++i) {
    for(int j = 1; j <= 3; ++j) {
      cin >> a[i][j];
      ++cnt[a[i][j]];
      row[i] += a[i][j];
      col[j] += a[i][j];
    }
  } 
  bool flag = 1;
  for(int i = 1; i <= 9; ++i) {
    if(!cnt[i]) {
      flag = 0;
      break;
    }
  }
  int num = row[1];
  for(int i = 1; i <= 3; ++i) {
    if(row[i] != num || col[i] != num) {
      flag = 0;
      break;
    }
  }
  if(a[1][1]+a[2][2]+a[3][3] != num || a[1][3]+a[2][2]+a[3][1] != num) flag = 0;
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}