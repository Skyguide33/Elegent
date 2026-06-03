//2026/2/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005], b[100005];

void solve() {
  int n, x; cin >> n >> x;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int l = 1, r = n;
  ll sum = 0, ans = 0;
  int idx = 0;
  while(l <= r) {
    while(l <= r && sum/x == (sum+a[r])/x) {
      sum += a[l];
      b[++idx] = a[l++];
    }
    if(l <= r) {
      sum += a[r];
      ans += a[r];
      b[++idx] = a[r--];
    }
  }
  cout << ans << endl;
  for(int i = 1; i <= n; ++i) cout << b[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}