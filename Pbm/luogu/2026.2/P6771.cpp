//2026/2/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Stair { int h, a, c; } s[401];

bool cmp(Stair &x, Stair &y) { return x.a < y.a; }

ll dp[40005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> s[i].h >> s[i].a >> s[i].c;
  sort(s+1, s+n+1, cmp);
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = s[i].a; j >= 1; --j) {
      for(int k = 1; k <= s[i].c && k*s[i].h <= j; ++k) {
        dp[j] += dp[j-k*s[i].h];
      }
    }
  }
  for(int i = s[n].a; i >= 0; --i) {
    if(dp[i]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}