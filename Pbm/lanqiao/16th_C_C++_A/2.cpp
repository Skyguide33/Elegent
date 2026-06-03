#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int a[6][6], vis[6][6] = {
  {1, 1, 0, 1, 0, 0},
  {0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1},
  {0, 1, 0, 0, 1, 0}
};

bool check() {
  set<int> r, c;
  for(int i = 0; i < 6; ++i) {
    int cnt = 0, state = 0, seq = 0;
    for(int j = 0; j < 6; ++j) {
      state <<= 1;
      if(a[i][j]) {
        cnt += a[i][j];
        state += a[i][j];
        if(++seq == 3) return 0;
      } else seq = 0;
    }
    if(cnt != 3) return 0;
    if(r.find(state) != r.end()) return 0;
    r.insert(state);
  } 
  for(int i = 0; i < 6; ++i) {
    int cnt = 0, state = 0, seq = 0;
    for(int j = 0; j < 6; ++j) {
      state <<= 1;
      if(a[j][i]) {
        cnt += a[j][i];
        state += a[j][i];
        if(++seq == 3) return 0;
      } else seq = 0;
    }
    if(cnt != 3) return 0;
    if(c.find(state) != c.end()) return 0;
    c.insert(state);
  }
  return 1;
}

int main() { 
  a[0][0] = a[4][2] = a[4][5] = a[5][4] = 1;
  for(int i = 0; i < (1<<26); ++i) {
    int state = i;
    for(int j = 0; j < 6; ++j) {
      for(int k = 0; k < 6; ++k) {
        if(!vis[j][k]) {
          a[j][k] = state&1;
          state >>= 1;
        }
      }
    }
    if(check()) {
      for(int j = 0; j < 6; ++j) {
        for(int k = 0; k < 6; ++k) {
          cout << a[j][k];
        }
      }
      break;
    }
  }
  cout << endl;
  return 0;
}