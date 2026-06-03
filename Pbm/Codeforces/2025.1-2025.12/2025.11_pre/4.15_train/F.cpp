//2025/4/15
#include <bits/stdc++.h>
using namespace std;

bool pos[200005][2];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    memset(pos, 0, sizeof(pos));
    int n; cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      int x, y; cin >> x >> y;
      pos[x][y] = 1;
    }
    for(int i = 0; i <= n; i++) {
      if(pos[i][0] && pos[i][1]) {
        ans += n - 2;
      }
    }
    for(int i = 1; i < n; i++) {
      if(pos[i-1][0] && pos[i][1] && pos[i+1][0]) ++ans;
    }
    for(int i = 1; i < n; i++) {
      if(pos[i-1][1] && pos[i][0] && pos[i+1][1]) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}