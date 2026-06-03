//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i];
  sort(a+1, a+n+1);
  sort(b+1, b+m+1);
  int cnt = 0, aidx = 1;
  ll ans = 0;
  bool flag = 1;
  for(int i = m; i >= 1; --i) {
    if(cnt >= b[i]) {
      ++aidx;
      cnt = 0;
    }
    if(aidx > n) {
      flag = 0;
      break;
    }
    ans += a[aidx];
    ++cnt;
  }
  if(flag) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}