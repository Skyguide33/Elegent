//2025/10/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define endl '\n'

int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}, pw[9];

struct pos {
  int x, y;
};

struct state_data {
  int state, x, y;
};

struct queue_data {
  int pri, depth, state, x, y;
  bool operator < (const queue_data &other) const { return pri > other.pri; }
};

vector<pos> get_hash(int state) {
  vector<pos> res(9);
  for(int i = 8; i >= 0; --i) {
    res[state%10] = {i/3, i%3};
    state /= 10;
  }
  return res;
}

int h(const vector<pos> &hash_c, const vector<pos> &hash_g) {
  double res = 0;
  for(int i = 0; i < 9; ++i) {
    res += abs(hash_c[i].x-hash_g[i].x) + abs(hash_c[i].y-hash_g[i].y);
  }
  return res;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  pw[0] = 1;
  for(int i = 1; i < 9; ++i) pw[i] = pw[i-1]*10;
  int src, des = 123804765; cin >> src;
  auto hd = get_hash(des); 
  int temp = src, sx = 0, sy = 0;
  for(int i = 8; i >= 0; --i) {
    if(temp%10 == 0) {
      sx = i/3; sy = i%3;
      break;
    }
    temp /= 10;
  }
  priority_queue<queue_data> q;
  map<int, int> visited;
  visited[src] = 0;
  q.push({h(get_hash(src), hd), 0, src, sx, sy});
  while (q.size()) {
    auto [temp, depth, state, x, y] = q.top(); q.pop();
    if(state == des) {
      cout << depth << endl;
      return 0;
    }
    ++depth;
    int pos_rev = 8-3*x-y;
    for(int i = 0; i < 4; ++i) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
        int n_pos_rev = 8-nx*3-ny;
        int n_num = state/pw[n_pos_rev]%10;
        int n_state = state+n_num*(pw[pos_rev]-pw[n_pos_rev]);
        if(!visited.count(n_state) || depth < visited[n_state]) {
          visited[n_state] = depth;
          q.push({depth+h(get_hash(state), hd), depth, n_state, nx, ny});
        }
      }
      
    }
  }
  return 0;
}