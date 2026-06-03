//2026/5/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

pair<ll, ll> p[100005], dp[100005];

ll fast_power(ll b, int p) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  if(k == 0) {
    cout << fast_power(n, m-1) << endl;
    return 0;
  }
  for(int i = 1; i <= k; ++i) {
    cin >> p[i].second >> p[i].first;
  }
  sort(p+1, p+k+1);
  if(p[1].first == 1) dp[1].first = 1;
  else {
    ll pre = fast_power(n, p[1].first-2);
    dp[1].first = (p[1].second-1)*pre%MOD;
    dp[1].second = (n-p[1].second)*pre%MOD;
  }
  for(int i = 2; i <= k; ++i) {
    if(p[i-1].first+1 == p[i].first) {
      dp[i].first = ((min(p[i-1].second, p[i].second)-1)*dp[i-1].first+max(0ll, p[i].second-p[i-1].second-1)*dp[i-1].second)%MOD;
      dp[i].second = ((n-max(p[i-1].second, p[i].second))*dp[i-1].second+max(0ll, p[i-1].second-p[i].second-1)*dp[i-1].first)%MOD;
    } else {
      ll pre = (dp[i-1].first*(p[i-1].second-1)+dp[i-1].second*(n-p[i-1].second))%MOD*fast_power(n, p[i].first-p[i-1].first-2)%MOD;
      dp[i].first = pre*(p[i].second-1)%MOD;
      dp[i].second = pre*(n-p[i].second)%MOD;
    } 
  }
  if(p[k].first == m) {
    cout << dp[k].second << endl;
  } else {
    ll ans = (dp[k].first*(p[k].second-1)+dp[k].second*(n-p[k].second))%MOD*fast_power(n, m-p[k].first-1)%MOD;
    cout << ans << endl;
  }
  return 0;
}