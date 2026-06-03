//2025/6/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

map<pair<int,int>, int> m;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int k = __gcd(abs(x1-x2), abs(y1-y2)); 
    int dx = (x2-x1) / k, dy = (y2-y1) / k;
    int x = x1, y = y1;
    for(int j = 0; j <= k; ++j) {
      ++m[{x+dx*j, y+dy*j}];
    }
  }
  int ans = 0;
  for(auto& [k, v]: m) {
    if(v >= 2) ++ans;
  }
  cout << ans << endl;
  return 0;
}