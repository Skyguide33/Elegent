//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], dp[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], dp[i] = INT_MAX>>1;
  dp[1] = a[1];
  int len = 1;
  for(int i = 2; i <= n; ++i) {
    if(dp[len] < a[i]) dp[++len] = a[i];
    else *upper_bound(dp+1, dp+len+1, a[i]) = a[i];
  }
  cout << n-len << endl;
  return 0;
}