//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int p1[100005], p[100005], dp[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, tt; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> tt, p1[tt] = i;
  for(int i = 1; i <= n; ++i) cin >> tt, p[i] = p1[tt], dp[i] = INT_MAX>>1;
  dp[1] = p[1];
  int len = 1;
  for(int i = 2; i <= n; ++i) {
    if(dp[len] < p[i]) dp[++len] = p[i];
    else *upper_bound(dp+1, dp+len+1, p[i]) = p[i];
  }
  cout << len << endl;
  return 0;
}  