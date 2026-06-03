//2025/8/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;



void solve() {
  ll n; cin >> n;  
  if(n%6 == 4) cout << 2 << endl;
  else cout << 0 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}
