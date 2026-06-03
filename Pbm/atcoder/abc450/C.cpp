//2026/3/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

char s[1005][1005];
int vis[1005][1005], h, w;

bool dfs(int x, int y) {
  vis[x][y] = 1;
  bool res = 1;
  if(x == 1 || x == h || y == 1 || y == w) res = 0;
  for(int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 1 || nx > h || ny < 1 || ny > w || vis[nx][ny] || s[nx][ny] == '#') continue;
    res &= dfs(nx, ny);
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> h >> w;
  for(int i = 1; i <= h; ++i) {
    for(int j = 1; j <= w; ++j) cin >> s[i][j];
  }
  int ans = 0;
  for(int i = 1; i <= h; ++i) {
    for(int j = 1; j <= w; ++j) {
      if(!vis[i][j] && s[i][j] == '.') {
        // cout << i << ' ' << j << endl;
        ans += dfs(i, j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}