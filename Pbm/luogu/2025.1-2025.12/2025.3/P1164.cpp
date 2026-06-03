//2025/3/21
#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
  int N, M, dish;
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> dish;
    for(int j = M; j >= 1; j--) {
      if(j == dish) dp[j]++;
      else if(j > dish) dp[j] += dp[j-dish];
    }
  }
  cout << dp[M];
  return 0;
}