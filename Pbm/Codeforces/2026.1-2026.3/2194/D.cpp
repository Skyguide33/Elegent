//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n+2, vector<int>(m+2));
  int tot = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      tot += a[i][j];
    }
  }
  for(int i = 1; i <= n; ++i) {
    a[i][m+1] = 0;
    for(int j = m; j >= 1; --j) a[i][j] += a[i][j+1];
  }
  int idx = 1, cnt = 0;
  int sum = tot/2; // 右上角需要凑够的1的数量
  cout << 1ll*sum*(tot-sum) << endl;
  for(int i = 1; i <= n; ++i) {
    while(idx < m+1 && cnt+a[i][idx] > sum) {
      ++idx;
      cout << 'R';
    }
    cnt += a[i][idx];
    cout << 'D';
  }
  while(idx < m+1) {
    ++idx;
    cout << 'R';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}