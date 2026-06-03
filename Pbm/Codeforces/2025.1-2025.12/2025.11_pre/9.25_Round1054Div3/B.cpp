//2025/9/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n, mx = 0; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  sort(a+1, a+n+1);
  ll ans = 0;
  for(int i = 2; i <= n; i += 2) ans = max(ans, a[i]-a[i-1]);
  cout << ans << endl; 
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}