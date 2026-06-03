//2025/7/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, aa[200005], dd[200005], dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int& a(int x, int y) { return aa[(x-1)*m+y-1]; }
int& d(int x, int y) { return dd[(x-1)*m+y-1]; }

void solve() {
  memset(dd, 0x3f, sizeof(dd));
  cin >> n >> m;
  queue<pair<int, int>> p;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) cin >> a(i,j);
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a(i,j)) d(i,j) = 0;
      else {
        if(i > 1) d(i,j) = min(d(i,j), d(i-1,j)+1);
        if(j > 1) d(i,j) = min(d(i,j), d(i,j-1)+1);
      }
    }
  }
  for(int i = n; i >= 1; --i) {
    for(int j = m; j >= 1; --j) {
      if(i < n) d(i,j) = min(d(i,j), d(i+1,j)+1);
      if(j < m) d(i,j) = min(d(i,j), d(i,j+1)+1);
    }
  }
  // for(int i = 1; i <= n; ++i) {
  //   for(int j = 1; j <= m; ++j) {
  //     d(i,j) = min({d(i,j), i+j-1, n+m-i-j+1, n-i+j, m-j+i});
  //   }
  // }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cout << d(i,j) << ' ';
    }
    cout << endl;
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) ans = max(ans, d(i,j));
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}