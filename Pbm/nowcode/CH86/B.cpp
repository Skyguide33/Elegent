//2026/3/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll b[1000005], n, m;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> b[i];
  int Q; cin >> Q;
  while(Q--) {
    ll k, l, r; cin >> k >> l >> r;
    set<ll> st = {l, r+1};
    --k;
    while(k > 1) {
      ll h = 1; 
      while((h<<1) < k) h <<= 1;
      vector<ll> temp;
      for(ll x: st) 
        if(x+h <= n*m) temp.push_back(x+h);
      for(ll x: temp) {
        if(st.contains(x)) st.erase(x);
        else st.insert(x);
      }
      k -= h;
    }
    ll ans = 0;
    for(ll j: st) {
      ll r = (j+n-1)/n, c = (j-1)%n+1;
      ans ^= b[c]+r-1;
    }
    cout << ans << endl;
  }
  return 0;
}