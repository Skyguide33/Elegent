//2025/8/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct rk {
  ll id, dist;
} d[100005];

bool cmp(rk& a, rk& b) {
  return a.dist < b.dist; 
}
void solve() {
  int n, H, h; cin >> n >> H;
  for(int i = 1; i <= n; ++i) {
    cin >> h; d[i] = {i, 1ll*h*(H-h)};
  } 
  sort(d+1, d+n+1, cmp);
  for(int i = 1; i <= n; ++i) cout << d[i].id << ' ';
  cout << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}

