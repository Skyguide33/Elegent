//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005], b[200005], pre[200005], suf[200005];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  ll ans = -1e18;
  for(int i = 1; i <= n; ++i) {
    pre[i] = pre[i-1]+a[i];
    if(pre[i] < 0) pre[i] = 0;
  }
  suf[n+1] = 0;
  for(int i = n; i >= 1; --i) {
    suf[i] = suf[i+1]+a[i];
    if(suf[i] < 0) suf[i] = 0;
  }
  for(int i = 1; i <= n; ++i) ans = max(ans, pre[i-1]+suf[i+1]+a[i]+(k%2? b[i]: 0));
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}