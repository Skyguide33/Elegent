//2026/4/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int s[1005][1005], p[1005][1005], n, m, vis[1005][1005];

bool check(int a) {
  for(int i = 1; i <= n; ++i) {
    fill(p[i]+1, p[i]+m+1, 0);
    fill(vis[i]+1, vis[i]+m+1, 0);
  }
  int fx = 0, fy = 0;
  for(int i = 1; i <= n-a+1; ++i) {
    for(int j = 1; j <= m-a+1; ++j) {
      if(s[i+a-1][j+a-1]-s[i+a-1][j-1]-s[i-1][j+a-1]+s[i-1][j-1] == a*a) {
        p[i][j] = 1;
        if(!fx) fx = i, fy = j; 
      }
    }
  }
  if(!fx) return 0;
  for(int i = fx; i < fx+a; ++i) fill(vis[i]+fy, vis[i]+fy+a, 1);
  queue<pair<int, int>> q;
  q.push({fx, fy});
  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 1 || ny < 1 || nx+a-1 > n || ny+a-1 > m || !p[nx][ny]) continue;
      if(i == 0) {
        for(int k = ny; k < ny+a; ++k) {
          if(vis[nx][k]) break;
          vis[nx][k] = 1;
        }
        for(int k = ny+a-1; k >= a; --k) {
          if(vis[nx][k]) break;
          vis[nx][k] = 1;
        }
      } else if(i == 1) {
        for(int k = nx; k < nx+a; ++k) {
          if(vis[k][ny+a-1]) break;
          vis[k][ny+a-1] = 1;
        }
        for(int k = nx+a-1; k >= nx; --k) {
          if(vis[k][ny+a-1]) break;
          vis[k][ny+a-1] = 1;
        }
      } else if(i == 2) {
        for(int k = ny; k < ny+a; ++k) {
          if(vis[nx+a-1][k]) break;
          vis[nx+a-1][k] = 1;
        }
        for(int k = ny+a-1; k >= a; --k) {
          if(vis[nx+a-1][k]) break;
          vis[nx+a-1][k] = 1;
        }
      } else {
        for(int k = nx; k < nx+a; ++k) {
          if(vis[k][ny]) break;
          vis[k][ny] = 1;
        }
        for(int k = nx+a-1; k >= nx; --k) {
          if(vis[k][ny]) break;
          vis[k][ny] = 1;
        }
      }
      p[nx][ny] = 0;
      q.push({nx, ny});
    }
  }
  int sum = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      sum += vis[i][j];
    }
  }
  return sum == s[n][m];
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    fill(s[i]+1, s[i]+m+1, 0);
    for(int j = 1; j <= m; ++j) {
      char ch; cin >> ch;
      s[i][j] = ch-'0'+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
    }
  }
  int l = 0, r = n; 
  while(l < r) {
    int mid = (l+r+1)>>1;
    if(check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}