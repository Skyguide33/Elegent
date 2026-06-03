//2025/11/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 100005

ll dp[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int c[4], d[4];
  for(int i = 0; i < 4; ++i) cin >> c[i];
  dp[0] = 1;
  for(int i = 0; i < 4; ++i) {
    for(int j = c[i]; j < N; ++j) dp[j] += dp[j-c[i]];
  }
  int T; cin >> T;
  while(T--) {
    for(int i = 0; i < 4; ++i) cin >> d[i];
    int s; cin >> s;
    ll ans = dp[s];
    for(int i = 1; i < 16; ++i) {
      int now = s, tmp = i, ov = 0;
      for(int j = 0; tmp; ++j) {
        if(tmp&1) ov ^= 1, now -= (d[j]+1)*c[j];
        tmp >>= 1;
      }
      if(now < 0) continue;
      if(ov) ans -= dp[now];
      else ans += dp[now];
    }
    cout << ans << endl;
  }
  return 0;
}