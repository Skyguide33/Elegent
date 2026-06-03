//2026/2/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[401][401];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  ll sum = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      sum += a[i][j];
    }
  }
  int flag = 1;
  if(n == 1) flag = 2;
  if(sum%(n*n)) flag = 0;
  if(flag == 1) {
    int tag = sum/(n*n);
    for(int i = 1; i < n; ++i) {
      for(int j = 1; j <= n; ++j) {
        int d = tag-a[i][j];
        if(d%2) {
          if(j == n) {
            flag = 0;
            break;
          } else {
            ++a[i][j]; ++a[i][j+1];
            --a[i+1][j]; --a[i+1][j+1];
            --d;
          }
        }
        if(j == n) {
          a[i][j] += d;
          a[i+1][j-1] -= d;
        } else {
          a[i][j] += d;
          a[i+1][j+1] -= d;
        }
      }
      if(!flag) break;
    }
    if(flag) {
      for(int i = 1; i <= n; ++i) {
        int d = tag-a[n][i];
        if(d%2 || (d && i+2 > n)) {
          flag = 0;
          break;
        }
        if(d) {
          a[n][i] += d;
          a[n][i+2] -= d;
        }
      }
    }
    // for(int i = 1; i <= n; ++i) {
    //   for(int j = 1; j <= n; ++j) cout << a[i][j] << ' ';
    //   cout << endl;
    // }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}