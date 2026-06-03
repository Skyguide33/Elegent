//2025/2/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[12][1<<11];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int h, w;
  while(1) {
    cin >> h >> w;
    if(h == 0) break;
    set<int> s;
    for(int i = 0; i < (1<<h); ++i) {
      int tt = i, cnt = 0, now;
      bool flag = 1;
      for(int j = 1; j <= h; ++j) {
        now = tt&1;
        if(!now) ++cnt;
        else if(cnt&1) {
          flag = 0;
          break;
        }
        tt >>= 1;
      }
      if(cnt&1) flag = 0;
      if(flag) s.insert(i);
    }
    for(int i = 0; i <= w; ++i) {
      for(int j = 0; j < (1<<h); ++j) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= w; ++i) {
      for(int b = 0; b < (1<<h); ++b) {
        for(int a = 0; a < (1<<h); ++a) {
          if(a&b || !s.contains(a|b)) continue;
          dp[i][b] += dp[i-1][a];
        }
      }
    }
    cout << dp[w][0] << endl;
  }
  return 0;
}