//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dp[11][10];

int sum(int x) {
  stack<int> st;
  while(x) {
    st.push(x%10);
    x /= 10;
  }
  int len = st.size(), now = 0, pre = 0, res = 0;
  for(int i = len; i >= 1; --i) {
    now = st.top(); st.pop();
    if(now < pre) break;
    for(int j = pre; j < now; ++j) res += dp[i][j];
    pre = now;
  }
  return res+(now >= pre);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  fill(dp[1], dp[2], 1);
  for(int i = 2; i <= 10; ++i) 
    for(int j = 0; j <= 9; ++j) 
      for(int k = j; k <= 9; ++k) dp[i][j] += dp[i-1][k];
  int a, b; 
  while(cin >> a >> b) cout << sum(b)-sum(a-1) << endl;
  return 0;
}