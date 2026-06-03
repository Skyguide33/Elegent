//2025/8/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool solve(int n, int m) {
  bool flag = 0;
  int yon = 2;
  if(n > m) {
    swap(n, m);
    flag = 1;
  }

  vector<vector<int>> a(n+1, vector<int> (m+1, 0));
  vector<int> row(n, m);

  // 0(1,0) 1(0,1) 2(-1,0) 3(0,-1)
  int r = 0, c = 0, dx = 1, dy = -1;
  for(int i = 1; i <= n*m; ++i) {
    // cout << "r=" << r << ", c=" << c << endl;
    if(a[r][c]) {
      yon = 1;
      break;
    }
    a[r][c] = i; 
    --row[r];
    if(row[r]) {
      dy *= -1;
      c = (c+(dy*i%m)+m) % m;
    } else {
      dx *= -1;
      r = (r+(dx*i%n)+n) % n;
    }
  }
  if(yon == 1) {
    // cout << "tt" << endl;
    fill(a.begin(), a.end(), vector<int> (m+1, 0));
    fill(row.begin(), row.end(), m);
    r = 0, c = 0, dx = 1, dy = 1;
    for(int i = 1; i <= n*m; ++i) {
      // cout << "r=" << r << ", c=" << c << endl;
      if(a[r][c]) {
        yon = 0;
        break;
      }
      a[r][c] = i; 
      --row[r];
      if(row[r]) {
        dy *= -1;
        c = (c+(dy*i%m)+m) % m;
      } else {
        dx *= -1;
        r = (r+(dx*i%n)+n) % n;
      }
    }
  }
  return yon;

  // if(yon) cout << "YES\n";
  // else {
  //   cout << "NO\n";
  //   return;
  // }
  // if(flag) {
  //   for(int j = 0; j < m; ++j) {
  //     for(int i = 0; i < n; ++i) cout << a[i][j] << ' ';
  //     cout << '\n';
  //   }
  // } else {
  //   for(int i = 0; i < n; ++i) {
  //     for(int j = 0; j < m; ++j) cout << a[i][j] << ' ';
  //     cout << '\n';
  //   }
  // }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 1; i <= 10; ++i) {
    for(int j = 1; j <= 10; ++j) {
      cout << solve(i, j) << ' ';
    }
    cout << endl;
  }
  return 0;
}