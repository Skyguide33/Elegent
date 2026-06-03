//2025/10/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n, m, k, h, a[100005], b[100005];

bool check(ll mid) {
  ll n1 = m, nh = k;
  for(ll i = 1; i <= n; ++i) {
    b[i] = a[i]; 
    ll r = max(0ll, mid-b[i]);
    ll costh = min(nh, r/h);
    b[i] += costh*h; nh -= costh;
  }
  sort(b+1, b+n+1);
  for(ll i = 1; i <= n; ++i) {
    if(nh && b[i] < mid) b[i] += h, --nh;
    ll r = max(0ll, mid-b[i]);
    ll cost1 = min(n1, r);
    b[i] += cost1; n1 -= cost1;
    if(b[i] < mid) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> k >> h;
  for(ll i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  ll l = 0, r = 1e18;
  while(l < r) {
    ll mid = (l+r+1)>>1;
    if(check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
  return 0;
}