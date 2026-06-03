//2026/5/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[33][33], k, b;

void init() {
  dp[0][0] = 1;
  for(int i = 1; i <= 32; ++i) {
    dp[i][0] = dp[i][i] = 1;
    for(int j = 1; j < i; ++j) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
  }
}

int sum(int x) {
  if(x == 0) return (k == 0);
  stack<int> st;
  while(x) {
    st.push(x%b);
    x /= b;
  }
  int len = st.size(), r = k, now = 0, res = 0;
  for(int i = len; i >= 1; --i) {
    now = st.top(); st.pop();
    if(now >= 2) {
      res += dp[i][r];
      break;
    } else if(now == 1) {
      res += dp[i-1][r];
      if(--r < 0) break;
    }
  }
  if(r == 0) ++res;
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int x, y; cin >> x >> y >> k >> b;
  init();
  cout << sum(y)-sum(x-1) << endl;
  return 0;
}