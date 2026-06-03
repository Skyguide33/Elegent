//2025/12/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int l, r, p, q; cin >> l >> r >> p >> q;
  int nl = (l+q-1)/q*q, nr = r/q*q;
  ll ans = 0;
  if(nl <= nr) {
    int st = l%q;
    if(st != 0 && st < p) ans += 1ll*(st+p-1)*(p-st)/2;
    int ed = r%q;
    ed = min(ed, p-1);
    ans += 1ll*(1+ed)*ed/2;
    int num = (nr-nl)/q;
    ans += 1ll*num*p*(p-1)/2;
  } else {
    int st = l%q, ed = min(p-1, r%q);
    if(st < p) ans = 1ll*(st+ed)*(ed-st+1)/2;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}