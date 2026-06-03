//2025/7/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ans;

void opt(ll a, ll b, int res) {
  if(res >= ans) return;
  else if(a == 0 || b == 0) {
    if(a == b) ans = res;
    else ans = res+1;
    return;
  }
  ll t = __gcd(a, b);
  opt(a-t, b, res+1);
  opt(a, b-t, res+1);
}

void solve() {
  ans = 5000;
  ll a, b; cin >> a >> b;
  opt(a, b, 0);
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}