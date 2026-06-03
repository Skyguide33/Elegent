//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int num_wide(ll n) {
  int res = 0;
  while(n) {
    ++res;
    n >>= 1;
  }
  return res;
}

void solve() {
  ll n; cin >> n;
  int w = num_wide(n);
  ll x = n<<w, y = x+n;
  cout << x << ' ' << y << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}