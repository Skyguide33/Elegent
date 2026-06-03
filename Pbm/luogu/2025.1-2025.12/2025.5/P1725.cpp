//2025/5/9
#include <bits/stdc++.h>
using namespace std;

int dp[200005];

inline int read() {
  int x = 0, f = 1; char ch = getchar();
  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ '0'); ch = getchar(); }
  return x * f;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int N = read(), L = read(), R = read();
  memset(dp, 0x80, sizeof(dp)); dp[0] = 0;
  deque<int> q(1, 0);
  for(int i = 0; i <= N; ++i) {
    int t = read();
    if(!q.empty() && q.front() < i-R) q.pop_front();
    for(int j = q.back()+1; j <= i-L; ++j) {
      while(!q.empty() && dp[q.back()] < dp[j]) q.pop_back();
      q.push_back(j);
    }
    if(i >= L) dp[i] = t + dp[q.front()];
  }
  int ans = -1e9;
  for(int i = N-R+1; i <= N; ++i) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}