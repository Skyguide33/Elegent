//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool vis[502][502];
int n, m, cnt, dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

void dfs(int x, int y) {
  for(int i = 0; i < 4; ++i) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 0 || ny < 0 || nx > n+1 || ny > m+1 || vis[nx][ny]) continue;
    vis[nx][ny] = 1;
    ++cnt;
    dfs(nx, ny);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  char t;
  for(int i = 1; i <= n; ++i) 
    for(int j = 1; j <= m; ++j) {
      cin >> t;
      if(t == '*') {
        vis[i][j] = 1; ++cnt;
      }
    }
  vis[0][0] = 0;
  dfs(0, 0);
  cout << (n+2)*(m+2)-cnt << endl;
  return 0;
}