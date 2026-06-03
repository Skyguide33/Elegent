//2025/6/14
#include <bits/stdc++.h>
using namespace std;

int a[1000005], dp[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int len = s.length();
  for(int i = 1; i <= len; ++i) a[i] = s[i-1]-'a'+1;
  dp[1] = a[1];
  if(len >= 2) dp[2] = a[2];
  for(int i = 3; i <= len; ++i) {
    dp[i] = max(dp[i-2], dp[i-3]) + a[i];
  }
  if(len >= 2) cout << max(dp[len-1], dp[len]) << endl;
  else cout << dp[1] << endl;
  return 0;
}