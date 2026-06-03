//2026/2/22
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], m[200005];

void solve() {
  int n; cin >> n;
  fill(m+1, m+n+1, 0);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i] == 1 || (i > 1 && m[i-1] == 0 && gcd(a[i-1], a[i]) == 1)) {
      ++ans;
      m[i] = 1;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}