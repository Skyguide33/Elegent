//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

int a[400005], b[200005];

int inv(int b) {
  int res = 1, p = MOD-2;
  while(p) {
    if(p&1) res = 1ll*res*b%MOD;
    b = 1ll*b*b%MOD;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int idx = 0;
  for(int i = 1; i <= 2*n; ++i) {
    cin >> a[i];
    if(a[i] != -1) b[++idx] = a[i];
  }
  sort(b+1, b+n+1);
  map<int, int> mp;
  idx = 0;
  int ans = 1, tot = 0;
  for(int i = 1; i <= 2*n; ++i) {
    if(a[i] == -1) {
      ans = 1ll*ans*(mp[b[++idx]]--)%MOD*inv(tot--)%MOD;
    } else {
      if(mp.contains(a[i])) ++mp[a[i]];
      else mp[a[i]] = 1;
      ++tot;
    }
  }
  cout << ans << endl;
  return 0;
}