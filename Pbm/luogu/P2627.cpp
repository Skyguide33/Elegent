//2026/6/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll e[100005], dp[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, k; cin >> n >> k;
  ll sum = 0;
  deque<int> q;
  q.push_back(0);
  for(int i = 1; i <= n; ++i) {
    cin >> e[i];
    sum += e[i];
    if(!q.empty() && q.front() < i-k-1) q.pop_front();
    dp[i] = dp[q.front()]+e[i];
    while(!q.empty() && dp[i] <= dp[q.back()]) q.pop_back();
    q.push_back(i);
    // cout << dp[i] << ' ';
  }
  // cout << endl;
  ll sub1 = 1e18;
  for(int i = n-k; i <= n; ++i) sub1 = min(sub1, dp[i]);
  cout << sum-sub1 << endl;
  return 0;
}