//2025/12/7
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll n; cin >> n;
  ll i = 0;
  for(; (1ll<<i) <= n; ++i);
  ll b = n-(1ll<<(i-1)), a = (1ll<<(i-1));
  for(int j = i-1; j >= 0; --j) {
    if(!(n&(1ll<<j)) && a+(1ll<<j) <= n) {
      a += (1ll<<j); b += (1ll<<j);
    }
  }
  cout << a+b << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; cin >> T;
  while(T--) solve();
  return 0;
}