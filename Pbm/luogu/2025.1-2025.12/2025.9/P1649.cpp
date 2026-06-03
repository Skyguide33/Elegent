//2025/9/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char a[102][102];
int n, b[102][102], sx, sy, tx, ty, dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

struct pos {
  int x, y, d, cnt;
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      b[i][j] = 1e9;
      cin >> a[i][j];
      if(a[i][j] == 'A') sx = i, sy = j; 
      else if(a[i][j] == 'B') tx = i, ty = j;
    }
  }
  queue<pos> q;
  b[sx][sy] = -1;
  q.push({sx, sy, -1, -1});
  while(!q.empty()) {
    auto [x, y, d, cnt] = q.front(); q.pop();
    if(b[x][y] < cnt) continue;
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 1 || ny < 1 || nx > n || ny > n || a[nx][ny] == 'x' || cnt+(d != i) > b[nx][ny]) continue;
      b[nx][ny] = cnt+(d != i);
      q.push({nx, ny, i, cnt+(d != i)});
    }
  }
  if(b[tx][ty] == 1e9) cout << -1 << endl;
  else cout << b[tx][ty] << endl;
  return 0;
}