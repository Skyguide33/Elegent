//2025/7/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

void solve() {
  ll n; cin >> n;
  for(ll i = 0; i < n; ++i) cin >> a[i];
  ll count, ans = 0, c;
  for(ll i = 0; i < n-1; ++i) {
    for(ll j = i+1; j < n; ++j) {
      count = 0;
      c = a[i]^a[j];
      for(ll k = 1; k < 1e8; k <<= 1) {
        if(k & c) {
          if(++count % 2 == 0) c -= k;
        }
      }
      ans += c;
    } 
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}