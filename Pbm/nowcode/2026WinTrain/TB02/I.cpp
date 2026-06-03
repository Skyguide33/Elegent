//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n+1, vector<int>(m+1));
  char tt;
  int cnt[2] = {0};
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> tt;
      a[i][j] = tt-'0';
      if(a[i][j]) ++cnt[1];
    }
  }
  cnt[0] = n*m-cnt[1];
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cout << "YN"[cnt[a[i][j]] < 2];
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}