//2025/4/8
#include <bits/stdc++.h>
using namespace std;

int N, K, a[11][11], v[11][11], rd[105];
int dy[8]={0,1,1,1,0,-1,-1,-1},dx[8]={-1,-1,0,1,1,1,0,-1};
bool ans = 0;

void dfs(int x, int y, int now, int len) {
  if(ans) return;
  if(x == N-1 && y == N-1 && len == N*N-1) {
    for(int i = 1; i <= len; i++) cout << rd[i];
    cout << endl;
    ans = 1;
    return;
  }
  int tag_n = (now+1) % K;
  for(int i = 0; i < 8; i++) {
    int nx = x+dx[i], ny = y+dy[i], nlen = len+1;
    if(nx < 0 || ny < 0 || nx >= N || ny >= N || v[nx][ny]) continue;
    if(i % 2 && (v[nx][y]&&v[x][ny]) || (len && abs(rd[len]-i) == 4)) continue;
    if(a[nx][ny] != tag_n) continue;
    v[nx][ny] = 1;
    rd[nlen] = i;
    dfs(nx,ny,tag_n,nlen);
    v[nx][ny] = 0;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) cin >> a[i][j];
  }
  v[0][0] = 1;
  dfs(0,0,0,0);
  if(!ans) cout << -1 << endl;
  return 0;
}