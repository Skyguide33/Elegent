//2025/11/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll a, b, c; cin >> a >> b >> c;
  ll mintme = 1e18, tme;
  for(int i = 0; i <= 30; ++i) {
    tme = 1ll*(i*a+c*b);
    c = (c+1)/2;
    if(tme <= mintme) mintme = tme;
  }
  cout << mintme << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}