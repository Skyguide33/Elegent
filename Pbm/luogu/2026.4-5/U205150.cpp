//2026/5/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[300005];
ll dp[300005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  map<int, int> pre;
  dp[0] = 1;
  for(int i = 1; i <= n; ++i) {
    dp[i] = (2*dp[i-1])%MOD;
    if(pre[a[i]]) dp[i] = (dp[i]-dp[pre[a[i]]-1]+MOD)%MOD;
    pre[a[i]] = i;
  }
  cout << dp[n] << endl;
  return 0;
}