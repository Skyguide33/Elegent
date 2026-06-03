//2026/2/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, w; cin >> n >> w;
  vector<int> a(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a.begin()+1, a.end());
  vector<int> dp(w+1, INT_MAX>>1);
  dp[0] = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= w; ++j) {
      if(j >= a[i]) dp[j] = min(dp[j], dp[j-a[i]]+1);
    }
  }
  // for(int i = 0; i <= w; ++i) cout << dp[i] << ' ';
  // cout << endl;
  cout << dp[w] << endl;
  return 0;
}