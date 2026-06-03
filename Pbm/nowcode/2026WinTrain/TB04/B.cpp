//2026/2/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll t[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, q, s; cin >> n >> q >> s;
  t[1] = s;
  for(int i = 2; i <= n+1; ++i) cin >> t[i], t[i] += t[i-1];
  while(q--) {
    ll x, y; cin >> x >> y;
    cout << t[x]+y-1 << endl;
  }
  return 0;
}