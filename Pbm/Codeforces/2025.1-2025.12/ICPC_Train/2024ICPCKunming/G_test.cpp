//2025/7/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll opt(ll a, ll b) {
  // cout << "a=" << a << ", b=" << b << endl;
  if(a == 0 && b == 0) return 0;
  else if(a == 0 || b == 0) return 1;
  ll t = __gcd(a, b);
  return min(opt(a-t,b), opt(a,b-t))+1;
}

void solve() {
  ll a, b; cin >> a >> b;
  cout << opt(a, b) << endl;

}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}