//2025/6/13
#include <bits/stdc++.h>
using namespace std;

bool bit[32];
int bitnum[32];

long long a[1005], b[1005], n, m;

struct dist {
  long long d, l, r;
} d[1000005];
int len = 0;

bool cmp(dist a, dist b) { return a.d < b.d; }

long long dp[1005][1005][2];

void init() {
  bitnum[0] = 1;
  for(int i = 1; i < 32; ++i) bitnum[i] = bitnum[i-1]*2;
}

int f(int x) {
  int maxbit = 0;
  for(; bitnum[maxbit] <= x; ++maxbit) {
    if(bitnum[maxbit] & x) bit[maxbit] = 1;
    else bit[maxbit] = 0;
  }
  --maxbit;
  int res = 0;
  for(int i = 0; i <= maxbit; ++i) {
    if(bit[i]) res += bitnum[maxbit-i];
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  init();
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = f(a[i]);
  }
  memset(dp, -1, sizeof(dp));
  dp[1][0][0] = a[1]; dp[1][1][1] = b[1];
  for(int i = 2; i <= n; ++i) {
    dp[i][0][0] = dp[i-1][0][0] + a[i];
    for(int j = 1; j < i; ++j) {
      dp[i][j][0] = max(dp[i-1][j][1], dp[i-1][j][0]) + a[i];
      dp[i][j][1] = max({dp[i-1][j-1][1], dp[i-1][j-1][0], dp[i-1][j][1]}) + b[i];
    }
    if(i <= m) dp[i][i][1] = dp[i-1][i-1][1] + b[i];
  }
  long long ans = -1;
  for(int i = 0; i <= m; ++i) {
    ans = max({ans, dp[n][i][0], dp[n][i][1]});
  }
  cout << ans << endl;
  return 0;
}