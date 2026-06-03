//2025/8/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool is_prime(int x) {
  int t = sqrt(x);
  for(int i = 2; i <= t; ++i)
    if(t % i == 0) return 0;
  return 1;
}

void solve() {
  ll g, l; cin >> g >> l;
  if(l % g != 0) {
    cout << 0 << endl;
    return;
  }
  l /= g;
  int ans = 1, flag = 1;
  for(int i = 2; i <= l; ++i) {
    if(flag) {
      if(is_prime(l)) {
        cout << ans*6 << endl;
        return;
      }
    }
    if(l%i == 0) {
      flag = 1;
      int cnt = 0;
      while(l%i == 0) {
        l /= i;
        ++cnt;
      }
      ans *= cnt*6;
    } else flag = 0;
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll T = 1; cin >> T;
  while(T--) solve();
  return 0;
}