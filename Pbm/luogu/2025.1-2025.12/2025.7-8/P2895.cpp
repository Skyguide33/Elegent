//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[303][303], dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};


struct State {
  int x, y, s;
};

void solve() {
  int m, x, y, t; cin >> m;
  for(int i = 0; i <= 302; ++i) {
    for(int j = 0; j <= 302; ++j) a[i][j] = INT_MAX;
  }
  while(m--) {
    cin >> x >> y >> t;
    a[x][y] = min(a[x][y], t);
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx >= 0 && nx <= 302 && ny >= 0 && ny <= 302) a[nx][ny] = min(a[nx][ny], t);
    }
  }
  int ans = -1;
  queue<State> q;
  q.push({0, 0, 0});
  while(!q.empty()) {
    auto [x, y, s] = q.front(); q.pop();
    if(a[x][y] == INT_MAX) {
      ans = s;
      break;
    }
    if(a[x][y] <= s) continue;
    a[x][y] = -s;
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 0 || nx > 302 || ny < 0 || ny > 302 || a[nx][ny] <= s+1) continue;
      q.push({nx, ny, s+1});
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}