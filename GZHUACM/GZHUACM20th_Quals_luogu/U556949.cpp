//2026/3/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int vis[100005], a[200005];
ll sum[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, x, m; cin >> n >> x >> m;
  sum[1] = a[1] = x%m;
  if(a[1] == 0) {
    cout << 0 << endl;
    return 0;
  }
  vis[a[1]] = 1;
  int flag = 1, srt = 0, ed = 0;
  for(int i = 2; i <= n; ++i) {
    a[i] = 1ll*a[i-1]*a[i-1]%m;
    sum[i] = sum[i-1]+a[i];
    if(a[i] == 0) {
      n = i;
      break;
    } else if(vis[a[i]]) {
      srt = vis[a[i]], ed = i-1;
      flag = 0;
      break;
    } 
    vis[a[i]] = i;
  }
  if(flag) cout << sum[n] << endl;
  else {
    ll ans = sum[srt-1];
    n -= srt-1;
    int T = ed-srt+1;
    ans += n/T*(sum[ed]-sum[srt-1])+sum[srt-1+n%T]-sum[srt-1];
    cout << ans << endl;
  }
  return 0;
}