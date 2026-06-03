//2026/2/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Tri {
  int x, y; 
  bool operator < (const Tri &B) const {
    return (double)y/x < (double)B.y/B.x;
  }
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, w; cin >> n >> w;
  priority_queue<Tri> q;
  for(int i = 1; i <= n; ++i) {
    int x, y; cin >> x >> y;
    q.push({x, y});
  }
  while(w) {
    auto [x, y] = q.top(); q.pop();
    if(y == 0) {
      q.push({x, 0});
      break;
    };
    q.push({x, y-1});
    --w;
  }
  double ans = 0.;
  while(!q.empty()) {
    auto [x, y] = q.top(); q.pop();
    ans += hypot(x, y);
  }
  cout << setprecision(9) << fixed << ans << endl;
  return 0;
}