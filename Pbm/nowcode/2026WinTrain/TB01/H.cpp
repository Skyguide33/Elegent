//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

void solve() {
  int n; cin >> n;
  vector<int> a(n+1), pre(n+1);
  int lst = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = lst;
    if(a[i]) lst = i;
  } 
  vector<int> dp(n+2), s(n+2);
  // dp[i] 满足[1, i]区间内擦除前后的结果相同的擦除方法个数, s[i]: dp[0]+dp[1]+...dp[i-1]
  s[1] = dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    int j = pre[i], val = a[i];
    while(j > 0 && !(val&a[j])) { 
      val |= a[j];
      j = pre[j];
    }
    dp[i] = (s[i]-s[j]+MOD)%MOD;
    s[i+1] = (s[i]+dp[i])%MOD;
  }
  cout << dp[n] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}