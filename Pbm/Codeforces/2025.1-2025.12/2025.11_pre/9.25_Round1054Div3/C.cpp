//2025/9/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

void solve() {
  int n, k, ans = 0; cin >> n >> k;
  for(int i = 0; i <= n; ++i) b[i] = 0;
  for(int i = 1; i <= n; ++i) cin >> a[i]; 
  sort(a+1, a+n+1);
  for(int i = 1; i <= n; ++i) ++b[a[i]];
  int cnt = 0;
  for(int i = 0; i < k; ++i) {
    if(!b[i]) ++cnt;
  }
  cnt -= b[k]; ans += b[k];
  ans += max(0, cnt);
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}