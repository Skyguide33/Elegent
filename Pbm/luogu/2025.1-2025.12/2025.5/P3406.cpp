//2025/5/28
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long

ll times[N], n, m, a[N], b[N], c[N], p[N];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> p[1];
  for(ll i = 2; i <= m; ++i) {
    cin >> p[i];
    ll l = min(p[i], p[i-1]), r = max(p[i], p[i-1]);
    ++times[l]; --times[r];
  }
  for(ll i = 1; i <= n-1; ++i) times[i] += times[i-1];
  for(ll i = 1; i <= n-1; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  long long ans = 0;
  for(ll i = 1; i <= n-1; ++i) {
    ans += min(times[i]*a[i], c[i]+times[i]*b[i]);
  }
  cout << ans << endl;
  return 0;
}