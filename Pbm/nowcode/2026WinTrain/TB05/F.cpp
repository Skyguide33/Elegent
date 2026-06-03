//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll n, a, b; cin >> n >> a >> b;
  ll ab = a+b;
  ll ans1 = n/2*b, ans2 = n/7*a, ans3 = n/8*ab;
  // 2最大
  for(ll i = 0; i <= min(60ll, n); ++i) {
    for(ll j = 0; j <= i; ++j) {
      ll n7 = j, n8 = i-j, n2 = n-n7-n8;
      ans1 = max(ans1, n2/2*b+n7/7*a+n8/8*ab);
    }
  } 
  // 7最大
  for(ll i = 0; i <= min(60ll, n); ++i) {
    for(ll j = 0; j <= i; ++j) {
      ll n2 = j, n8 = i-n2, n7 = n-n2-n8;
      ans2 = max(ans2, n2/2*b+n7/7*a+n8/8*ab);
    }
  } 
  // 8最大
  for(ll i = 0; i <= min(60ll, n); ++i) {
    for(ll j = 0; j <= i; ++j) {
      ll n2 = j, n7 = i-n2, n8 = n-n2-n7;
      ans3 = max(ans3, n2/2*b+n7/7*a+n8/8*ab);
    }
  } 
  cout << max({ans1, ans2, ans3}) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}