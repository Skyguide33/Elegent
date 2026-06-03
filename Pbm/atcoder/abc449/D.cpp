//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int l, r, d, u; cin >> l >> r >> d >> u;
  if(r <= 0) {
    l *= -1, r *= -1;
    swap(l, r);
  }
  if(u <= 0) {
    u *= -1, d *= -1;
    swap(u, d);
  }
  ll ans = 0;
  if(l <= 0 && 0 <= r) {
    if(d <= 0 && 0 <= u) ++ans;
    ans += u/2;
    if(d > 0) ans -= (d-1)/2;
    else ans += -d/2;
  }
  for(int i = d; i <= u; ++i) {
    if(i&1) {
      ans += max(0, (r-abs(i)+1))/2;
      if(l < 0) {
        ans += max(0, (-l-abs(i)+1))/2;
      } else ans -= max(0, (l-abs(i)))/2;
    } else {
      ans += min(abs(i), r)+max(0, r-abs(i))/2;
      if(l <= 0) ans += min(abs(i), -l)+max(0, -l-abs(i))/2;
      else ans -= min(abs(i), l-1)+max(0, l-abs(i)-1)/2;
    }
  }
  cout << ans << endl;
  return 0;
}