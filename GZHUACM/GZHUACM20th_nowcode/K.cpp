//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
int a[200005], b[200005], c[200005];
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, x; cin >> n >> x;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  sort(a+1, a+n+1);
  // for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  // cout << endl;
  auto check = [&](int mid)->bool {
    for(int i = 1; i <= mid; ++i) c[i] = b[i];
    sort(c+1, c+mid+1);
    ll sum = 0;
    for(int i = 0; i < mid; ++i) {
      // cout << 
      sum += 1ll*a[n-i]*c[mid-i];
    }
    // cout << "mid=" << mid << ", sum=" << sum << ' ' << x << endl;
    // for(int i = 1; i <= mid; ++i) cout << c[i] << ' ';
    // cout << endl;
    return sum >= x;
  };
  int l = 1, r = n+1;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  if(l == n+1) cout << -1 << endl;
  else cout << l << endl;
  return 0;
}