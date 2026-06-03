//2026/2/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll x, y, k, b, dp[32][32];

int sum(int num) {
  stack<int> st;
  while(num) {
    st.push(num%b);
    num /= b;
  }
  stack<int> ss(st);
  while(!ss.empty()) {
    // cout << ss.top() << ' ';
    ss.pop();
  }
  // cout << endl;
  int len = st.size(), last = 0, res = 0;
  for(int i = len; i >= 1; --i) {
    int now = st.top(); st.pop();
    if(now) {
      res += dp[i-1][k-last];
      if(now > 1) {
        if(k-last-1 >= 0) res += dp[i-1][k-last-1];
        break;
      } else {
        ++last;
        if(last > k) break;
      }
    } 
    if(i == 1 && last == k) ++res;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> x >> y >> k >> b;
  int len = log(INT_MAX)/log(b)+1;
  // cout << "len=" << len << endl;
  dp[0][0] = 1;
  for(int i = 1; i <= len; ++i) {
    dp[i][0] = dp[i][i] = 1;
    for(int j = 1; j < i; ++j) {
      dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
    }
  }
  // cout << "k=" << k << endl;
  // for(int i = 1; i <= len; ++i) cout << dp[i][k] << ' ';
  // cout << endl;
  // cout << x << ' ' << y << ' ' << k << ' ' << b << endl;
  cout << sum(y)-sum(x) << endl;
  return 0;
}