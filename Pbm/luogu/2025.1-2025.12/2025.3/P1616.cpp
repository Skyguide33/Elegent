//2025/3/21
#include <bits/stdc++.h>
using namespace std;

long long a, b, mul, dp[10000005];

int main() {
  int t, m;
  cin >> t >> m;
  for(int i = 1; i <= m; i++) {
    cin >> a >> b;
    for(int j = a; j <= t; j++) {
      dp[j] = max(dp[j], dp[j-a]+b);
    }
  }
  cout << dp[t] << endl;
  return 0;
}

