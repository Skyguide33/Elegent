//2025/11/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, tt; cin >> n;
  vector<int> dp(n+1);
  vector<queue<int>> q(n+1);
  for(int i = 1; i <= n; ++i) {
    dp[i] = dp[i-1];
    q[cin >> tt, tt].push(i);
    if(q[tt].size() == tt) {
      dp[i] = max(dp[i], dp[q[tt].front()-1]+tt);
      q[tt].pop();
    }
  }
  cout << dp[n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}