//2026/5/18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int l, r, k; cin >> l >> r >> k;
  int nl = l/k, nr = r/k;
  ll ans = 0;
  int ml = l-nl*k, mr = r-nr*k;
  if(nl != nr) {
    // cout << 1ll*(nr-nl-2)*(nr-nl-1)/2*k << endl;
    ans = 1ll*(nr-nl-2)*(nr-nl-1)/2*k;
    // cout << "a2=" << 1ll*(nr-nl-1)*(k-ml) << ' ' << 1ll*(nr-nl-1)*(mr+1) << endl;
    ans += 1ll*(nr-nl-1)*(k-ml+mr+1);
    ans += max(0, mr-ml+1);
  } 
  // cout << "max(0, mr-ml+1)=" << max(0, mr-ml+1) << endl;
  cout << ans << endl;
  return 0;
}