//2025/8/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m; cin >> n >> m;
  bool flag = 0;
  int yon = 2;
  if(n > m) {
    swap(n, m);
    flag = 1;
  }
  vector<vector<int>> a(n, vector<int> (m, 0));
  vector<int> row(n, m);

  int r = 0, c = 0, dx = 1, dy = -1;
  for(int i = 1; i <= n*m; ++i) {
    if(a[r][c]) {
      yon = 1;
      break;
    }
    a[r][c] = i; 
    if(--row[r]) {
      dy *= -1;
      c = (c+(dy*i%m)+m) % m;
    } else {
      dx *= -1;
      r = (r+(dx*i%n)+n) % n;
    }
  }
  if(yon == 1) {
    fill(a.begin(), a.end(), vector<int> (m, 0));
    fill(row.begin(), row.end(), m);
    r = 0, c = 0, dx = 1, dy = 1;
    for(int i = 1; i <= n*m; ++i) {
      if(a[r][c]) {
        yon = 0;
        break;
      }
      a[r][c] = i;
      if(--row[r]) {
        dy *= -1;
        c = (c+(dy*i%m)+m) % m;
      } else {
        dx *= -1;
        r = (r+(dx*i%n)+n) % n;
      }
    }
  }
  if(yon) cout << "YES\n";
  else {
    cout << "NO\n";
    return;
  }
  if(flag) {
    for(int j = 0; j < m; ++j) {
      for(int i = 0; i < n; ++i) cout << a[i][j] << ' ';
      cout << '\n';
    }
  } else {
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) cout << a[i][j] << ' ';
      cout << '\n';
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}