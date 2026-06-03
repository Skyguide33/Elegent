//2026/2/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  int ans[3] = {0}, cnt = 0;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  if(n > 1000) {
    for(int i = 1; i <= n; ++i) {
      if(a[i]%2 == 0) ans[++cnt] = a[i];
      if(cnt == 2) break;
    }
  } else {
    for(int i = 1; i <= n; ++i) {
      for(int j = i+1; j <= n; ++j) {
        if(gcd(a[i], a[j]) > 1) {
          ans[1] = a[i], ans[2] = a[j], cnt = 2;
          break;
        }
      }
      if(cnt) break;
    }
  }
  if(cnt) cout << ans[1] << ' ' << ans[2] << endl;
  else cout << -1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}