//2025/6/14
#include <bits/stdc++.h>
using namespace std;

int n, r[21], c[21], a[21][21], v[21][21], d[401], tail;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
bool found = 0;

void dfs(int x, int y) {
  if(x == n-1 && y == n-1) {
    found = 1;
    for(int i = 0; i < n; ++i) {
      if(r[i] != 0 || c[i] != 0) {
        found = 0;
        break;
      }
    }
    return;
  }
  for(int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx<0 || ny<0 || nx==n || ny==n || v[nx][ny]) continue;
    if(c[nx] == 0 || r[ny] == 0) continue;
    d[++tail] = a[nx][ny];
    --c[nx]; --r[ny];
    v[nx][ny] = 1;
    dfs(nx, ny);
    if(found) return;
    v[nx][ny] = 0;
    ++c[nx]; ++r[ny];
    --tail;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> r[i];
  for(int i = 0; i < n; ++i) cin >> c[i];
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) a[i][j] = cnt++;
  }
  --r[0]; --c[0];
  d[0] = 0;
  v[0][0] = 1;
  dfs(0,0);
  for(int i = 0; i <= tail; ++i) cout << d[i] << ' ';
  cout << endl;
  return 0;
}