//2025/9/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, ans, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
char a[22][22];
bool v[22][22];

void dfs(int x, int y) {
  v[x][y] = 1; ++ans;
  for(int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
    if(v[nx][ny] || a[nx][ny] != '.') continue;
    dfs(nx, ny);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  while(cin >> m >> n) {
    if(n == 0) break;
    int sx = 0, sy = 0;
    for(int i = 1; i <= n; ++i) 
      for(int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        if(a[i][j] == '@') {
          sx = i; sy = j;
        }
      }
    ans = 0;
    for(int i = 1; i <= n; ++i) 
      for(int j = 1; j <= m; ++j) v[i][j] = 0;
    dfs(sx, sy);
    cout << ans << endl;
  }
  return 0;
}