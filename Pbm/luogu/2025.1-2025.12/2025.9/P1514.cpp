//2025/9/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int a[502][502], l[502][502], r[502][502];
bool vis[502][502];

void dfs(int x, int y) {
  vis[x][y] = 1;
  for(int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 1 || ny < 1 || nx > n || ny > m || a[x][y] <= a[nx][ny]) continue;
    if(!vis[nx][ny]) dfs(nx, ny);
    l[x][y] = min(l[x][y], l[nx][ny]);
    r[x][y] = max(r[x][y], r[nx][ny]);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) 
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      l[i][j] = 501;
    }
  for(int j = 1; j <= m; ++j) l[n][j] = r[n][j] = j;
  for(int j = 1; j <= m; ++j)
    if(!vis[1][j]) dfs(1, j);
  int ans = m;
  for(int j = 1; j <= m; ++j) ans -= vis[n][j];
  if(ans) {
    cout << 0 << endl << ans << endl;
    return 0;
  }
  int left = 1, right = r[1][1];
  while(left <= m) {
    for(int i = 1; i <= m; ++i) 
      if(l[1][i] <= left) right = max(right, r[1][i]);
    left = right+1;
    ++ans;
  }
  cout << 1 << endl << ans << endl;
  return 0;
}