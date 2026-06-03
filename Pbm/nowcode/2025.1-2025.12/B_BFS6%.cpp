//2025/7/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long

char ss[1000005];
int n, m, k, d[1000005], dx[4] = {0,-1,1,0}, dy[4] = {-1,0,0,1};

char& s(const int& i, const int& j) { return ss[(i-1)*m+j-1]; }
int& dp(const int& i, const int& j) { return d[(i-1)*m+j-1]; }

void solve() {
  memset(d, -1, sizeof(d));
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> s(i,j);
  }
  queue<pair<int, int>> q;
  q.push({1, m});
  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    dp(x,y) = -2;
    for(int i = 0; i < 3; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if(s(nx,ny) == '1' || dp(nx,ny) == -2) continue;
      q.push({nx, ny});
    }
  }
  q.push({1, 1});
  dp(1,1) = 0;
  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for(int i = 1; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i], t = dp(x,y)+dy[i];
      if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if(s(nx,ny) == '1' || dp(nx,ny) >= t) continue;
      if(dp(nx,ny) == -2) dp(nx,ny) = 0;
      else dp(nx,ny) = t;
      q.push({nx, ny});
    }
  }
  // for(int i = 1; i <= n; ++i) {
  //   for(int j = 1; j <= m; ++j) {
  //     cout << dp(i,j) << ' ';
  //   }
  //   cout << endl;
  // }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(dp(i,j) >= k) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}