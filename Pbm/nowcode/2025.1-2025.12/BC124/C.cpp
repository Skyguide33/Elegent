//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int kx[8] = { -1,-1,0,1,1,1,0,-1 }, ky[8] = { 0,1,1,1,0,-1,-1,-1};
int hx[8] = { -2,-1,1,2,2,1,-1,-2 }, hy[8] = { 1,2,2,1,-1,-2,-2,-1 };

void solve() {
  int x, y, n; cin >> x >> y >> n;
  set<pair<int, int>> go, ct;
  for(int i = 0; i < 8; ++i) {
    go.insert({x+kx[i], y+ky[i]});
  }
  for(int i = 1; i <= n; ++i) {
    int tx, ty; cin >> tx >> ty;
    for(int i = 0; i < 8; ++i) {
      ct.insert({tx+hx[i], ty+hy[i]});
    }
  }
  bool jj = ct.count({x, y}), bh = 1;
  for(auto g: go) {
    if(!ct.count(g)) {
      bh = 0;
      break;
    }
  }
  if(bh) {
    if(jj) cout << 'B' << endl;
    else cout << 'A' << endl;
  } else cout << 'C' << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}