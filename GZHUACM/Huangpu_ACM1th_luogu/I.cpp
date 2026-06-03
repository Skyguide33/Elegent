//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Pos {
  int x, y;
} p[100005];

bool cmp1(const Pos &a, const Pos &b) {
  if(a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

bool cmp2(const Pos &a, const Pos &b) {
  if(a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
map<int, vector<int>> mpr, mpc;
set<pair<int, int>> stp;
set<pair<int, int>> vis;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int h, w, n; cin >> h >> w >> n;
  int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
  for(int i = 1; i <= n; ++i) {
    cin >> p[i].x >> p[i].y;
    stp.insert({p[i].x, p[i].y});
  }
  bool flag = 0;
  if(!stp.contains({gx, gy}) && !stp.contains({sx, sy})) {
    for(int i = 0; i < 4; ++i) {
      int nx = gx+dx[i], ny = gy+dy[i];
      if(nx < 1 || ny < 1 || nx > h || ny > w || !stp.contains({nx, ny})) continue;
      flag = 1;
      break;
    }
  }
  if(!flag) {
    cout << -1 << endl;
    return 0;
  }
  sort(p+1, p+n+1, cmp1);
  for(int i = 1; i <= n; ++i) mpr[p[i].x].push_back(p[i].y);
  sort(p+1, p+n+1, cmp2);
  for(int i = 1; i <= n; ++i) mpc[p[i].y].push_back(p[i].x);
  queue<tuple<int, int, int>> q;
  q.push({sx, sy, 0});
  vis.insert({sx, sy});
  while(!q.empty()) {
    auto [x, y, d] = q.front(); q.pop();
    // cout << x << ' ' << y << ' ' << d << endl;
    if(x == gx && y == gy) {
      cout << d << endl;
      return 0;
    }
    int nx = 0, ny = 0;
    if(mpr.contains(x)) {
      int ny_pos2 = upper_bound(mpr[x].begin(), mpr[x].end(), y)-mpr[x].begin(), ny_pos1 = ny_pos2-1;
      if(ny_pos1 >= 0 && y != mpr[x][ny_pos1]+1) {
        nx = x; ny = mpr[x][ny_pos1]+1;
        if(!vis.contains({nx, ny})) {
          q.push({nx, ny, d+1});
          vis.insert({nx, ny});
        }
      }
      if(ny_pos2 < (int)mpr[x].size() && y != mpr[x][ny_pos2]-1) {
        nx = x; ny = mpr[x][ny_pos2]-1;
        if(!vis.contains({nx, ny})) {
          q.push({nx, ny, d+1});
          vis.insert({nx, ny});
        }
      }
    } 
    if(mpc.contains(y)) {
      int nx_pos2 = upper_bound(mpc[y].begin(), mpc[y].end(), x)-mpc[y].begin(), nx_pos1 = nx_pos2-1;
      if(nx_pos1 >= 0 && x != mpc[y][nx_pos1]+1) {
        nx = mpc[y][nx_pos1]+1; ny = y;
        if(!vis.contains({nx, ny})) {
          q.push({nx, ny, d+1});
          vis.insert({nx, ny});
        }
      }
      if(nx_pos2 < (int)mpc[y].size() && x != mpc[y][nx_pos2]-1) {
        nx = mpc[y][nx_pos2]-1; ny =  y;
        if(!vis.contains({nx, ny})) {
          q.push({nx, ny, d+1});
          vis.insert({nx, ny});
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}