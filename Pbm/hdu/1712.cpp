//2025/4/19
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a[101][101], dp[101]; 
  while(cin >> N >> M && N && M) {
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; ++i) 
      for(int j = 1; j <= M; ++j) cin >> a[i][j];
    for(int i = 1; i <= N; ++i)
      for(int j = M; j >= 1; --j) 
        for(int k = 1; k <= j; ++k) 
          dp[j] = max(dp[j], dp[j-k]+a[i][k]);
    cout << dp[M] << endl;
  } 
  return 0;
}