//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll m, vis[10000005];

ll fast_power(ll b, ll p, ll mod) {
  ll res = 1;
  while(p) {
    if(p&1) res = (res*b)%mod;
    b = (b*b)%mod;
    p >>= 1; 
  }
  return res;
}

void solve() {
  cin >> m;
  for(int i = 0; i < m; ++i) vis[i] = 0;
  for(int i = 0; i <= 2*m; ++i) {
    ll t = fast_power(2, i, m);
    cout << t << ' ';
    if(vis[t] == 0) {
      vis[t] = 1;
    } 
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}