//2026/5/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// dp[i][j][k]位数为i的最高位为k的数字中出现数字j的总次数
ll dp[13][10][10], pw[13];

vector<ll> sum(ll x) {
  vector<ll> res(10), tmp(10);
  res[0] = 1;
  if(x == 0) return res;
  stack<int> st;
  while(x) {
    st.push(x%10);
    x /= 10;
  }
  int len = st.size();
  for(int i = len; i >= 1; --i) {
    int num = st.top(); st.pop();
    for(int j = 0; j < 10; ++j) {
      for(int k = (i == len); k < num; ++k) {
        res[j] += dp[i][j][k];
      }
      res[j] += 1ll*num*pw[i]*tmp[j];
    }
    ++tmp[num];
  }
  for(int i = 0; i < 10; ++i) res[i] += tmp[i];
  for(int i = len-1; i >= 1; --i) {
    for(int j = 0; j < 10; ++j) {
      for(int k = 1; k < 10; ++k) res[j] += dp[i][j][k];
    }
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  pw[1] = 1;
  for(int i = 2; i <= 12; ++i) pw[i] = pw[i-1]*10;
  for(int i = 1; i <= 12; ++i) {
    for(int j = 0; j < 10; ++j) {
      for(int k = 0; k < 10; ++k) {
        for(int l = 0; l < 10; ++l) {
          dp[i][j][k] += dp[i-1][j][l];
        }
        if(j == k) dp[i][j][k] += pw[i];
      }
    }
  }

  vector<ll> ans(10);
  ll a, b; cin >> a >> b;
  auto res1 = sum(a-1); 
  auto res2 = sum(b);
  for(int i = 0; i < 10; ++i) cout << res2[i]-res1[i] << ' ';
  cout << endl;
  return 0;
}
