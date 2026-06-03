//2026/3/24
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int a[200005], n, h;

bool check(int k) {
  int mina = INT_MAX>>1, maxa = 0;
  int sum = 0;
  for(int i = 1; i <= k; ++i) {
    mina = min(mina, a[i]);
    sum += a[i];
  }
  for(int i = k+1; i <= n; ++i) maxa = max(maxa, a[i]);
  sum += max(0ll, maxa-mina);
  return sum >= h;
}

void solve() {
  int k; cin >> n >> h >> k;
  int sum = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int cnt = h/sum;
  int ans = cnt*(n+k);
  h -= cnt*sum;
  if(h == 0) {
    cout << ans-k << endl;
    return;
  }
  int l = 1, r = n;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  cout << ans+l << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}