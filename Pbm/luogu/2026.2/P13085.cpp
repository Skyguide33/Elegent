//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll dp[20][10];

ll sum(ll x) {
  stack<int> st;
  while(x) {
    st.push(x%10);
    x /= 10;
  }
  int len = st.size(), now = -2, pre = -2;
  ll res = 0;
  for(int i = len; i >= 1; --i) {
    pre = now;
    now = st.top(); st.pop();
    for(int j = (i==len); j < now; ++j)
      if(abs(j-pre) >= 2) res += dp[i][j];
    if(abs(now-pre) < 2) break;
  }
  for(int i = len-1; i >= 1; --i)
    for(int j = 1; j <= 9; ++j) res += dp[i][j];
  return res+(abs(now-pre) >= 2);
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  fill(dp[1], dp[2], 1);
  for(int i = 1; i <= 19; ++i) 
    for(int j = 0; j <= 9; ++j) 
      for(int k = 0; k <= 9; ++k) 
        if(abs(j-k) >= 2) dp[i][j] += dp[i-1][k];
  ll a, b; cin >> a >> b;
  cout << sum(b)-sum(a-1) << endl;
  return 0;
}