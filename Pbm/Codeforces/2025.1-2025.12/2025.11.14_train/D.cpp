//2025/11/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll x, y, k; 

bool check(ll mid) {
  for(int i = 1; i <= x; ++i) mid -= mid/y;
  if(mid >= k) return 1;
  return 0;
}
void solve() {
  cin >> x >> y >> k;
  ll l = 1, r = 1e12+1;
  while(l < r) {
    ll mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  if(l == 1e12+1) cout << -1 << endl;
  else cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}