//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[300005], b[300005], n;
pair<ll, ll> p;

bool check(int k) {
  ll cil = 1e18, flr = -1e18;
  for(int i = 1; i <= n; ++i) {
    cil = min(cil, a[i]+1ll*k*b[i]);
    flr = max(flr, a[i]-1ll*k*b[i]);
    if(cil < flr) return 0;
  }
  return 1;
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  int l = 0, r = 1e9;
  while(l < r) {
    int mid = (l+r)>>1;
    if(check(mid)) r = mid;
    else l = mid+1;
  }
  cout << l << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}