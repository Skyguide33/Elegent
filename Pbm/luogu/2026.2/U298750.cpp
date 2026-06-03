//2026/2/17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[2][3];
// j{0:已购入 1:冷冻期 2:未购买}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  memset(dp, 0xbf, sizeof(dp));
  int now = 1, old = 0;
  dp[now][2] = 0;
  for(int i = 1; i <= n; ++i) {
    swap(now, old);
    int a; cin >> a;
    dp[now][0] = max({dp[old][0], dp[old][2]-a});
    dp[now][1] = dp[old][0]+a;
    dp[now][2] = max(dp[old][2], dp[old][1]);
  }
  cout << max(dp[now][1], dp[now][2]) << endl;
  return 0;
}