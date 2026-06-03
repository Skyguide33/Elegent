//2026/2/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[501][501], b[501][501];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, q; cin >> n >> m >> q;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) cin >> a[i][j];
  }
  ll maxn = 0, mx = 1, my = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      b[i][j] = a[i][j];
      if(i > 1) b[i][j] += a[i-1][j];
      if(i > 2) b[i][j] += a[i-2][j];
      if(i < n) b[i][j] += a[i+1][j];
      if(i < n-1) b[i][j] += a[i+2][j];
      if(j > 1) b[i][j] += a[i][j-1];
      if(j > 2) b[i][j] += a[i][j-2];
      if(j < m) b[i][j] += a[i][j+1];
      if(j < m-1) b[i][j] += a[i][j+2];
      if(i > 1 && j > 1) b[i][j] += a[i-1][j-1];
      if(i > 1 && j < m) b[i][j] += a[i-1][j+1];
      if(i < n && j > 1) b[i][j] += a[i+1][j-1];
      if(i < n && j < m) b[i][j] += a[i+1][j+1];
      if(b[i][j] > maxn) maxn = b[i][j], mx = i, my = j;
    }
  }
  while(q--) {
    int x, y, z; cin >> x >> y >> z;
    if((b[x][y] += z) > maxn) maxn = b[x][y], mx = x, my = y;
    if(x > 1 && (b[x-1][y] += z) > maxn) maxn = b[x-1][y], mx = x-1, my = y;
    if(x > 2 && (b[x-2][y] += z) > maxn) maxn = b[x-2][y], mx = x-2, my = y;
    if(x < n && (b[x+1][y] += z) > maxn) maxn = b[x+1][y], mx = x+1, my = y;
    if(x < n-1 && (b[x+2][y] += z) > maxn) maxn = b[x+2][y], mx = x+2, my = y;
    if(y > 1 && (b[x][y-1] += z) > maxn) maxn = b[x][y-1], mx = x, my = y-1;
    if(y > 2 && (b[x][y-2] += z) > maxn) maxn = b[x][y-2], mx = x, my = y-2;
    if(y < m && (b[x][y+1] += z) > maxn) maxn = b[x][y+1], mx = x, my = y+1;
    if(y < m-1 && (b[x][y+2] += z) > maxn) maxn = b[x][y+2], mx = x, my = y+2;
    if(x > 1 && y > 1 && (b[x-1][y-1] += z) > maxn) maxn = b[x-1][y-1], mx = x-1, my = y-1;
    if(x > 1 && y < m && (b[x-1][y+1] += z) > maxn) maxn = b[x-1][y+1], mx = x-1, my = y+1;
    if(x < n && y > 1 && (b[x+1][y-1] += z) > maxn) maxn = b[x+1][y-1], mx = x+1, my = y-1;
    if(x < n && y < m && (b[x+1][y+1] += z) > maxn) maxn = b[x+1][y+1], mx = x+1, my = y+1;
    cout << mx << ' ' << my << endl;
  } 
  return 0;
}