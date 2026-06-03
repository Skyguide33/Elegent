//2026/4/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

ll a[100005], b[100005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  map<double, set<int>> mp;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    mp[double(a[i])/b[i]].insert(i);
  }
  if(n == 1) {
    cout << a[1]+b[1]*m << endl;
    return 0;
  }
  while(m) {
    if(m > n && mp.begin()->first+1 > mp.rbegin()->first) {
      int times = m/n;
      m %= n;
      mp.clear();
      for(int i = 1; i <= n; ++i) {
        a[i] += times*b[i];
        mp[double(a[i])/b[i]].insert(i);
      }
    } else {
      int id = *(mp.begin()->second.begin()); 
      mp.begin()->second.erase(id);
      if(mp.begin()->second.empty()) mp.erase(mp.begin());
      double target = mp.begin()->first;
      int d = target-double(a[id])/b[id]+1;
      int sub1 = min(d, m);
      m -= sub1;
      a[id] += sub1*b[id];
      mp[double(a[id])/b[id]].insert(id);
    }
  }
  ll ans = 1;
  for(int i = 1; i <= n; ++i) {
    ans = ans*(a[i]%MOD)%MOD;
  }
  cout << ans << endl;
  return 0;
}