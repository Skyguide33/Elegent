//2025/12/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll pw[19];

ll get_numbers(ll x) {
  ll res = 0;
  while(x) {
    x /= 10;
    ++res;
  }
  return res;
}

void solve() {
  ll x, a, b, c; cin >> x >> a >> b >> c;
  ll ans = 1e18;
  ll num = get_numbers(x);
  ll ansa = 0;
  while(num >= 0) {
    // cout << "x=" << x << endl;
    ll ofs = max(0ll, num-4);
    ll x4 = x/pw[ofs];
    if(x4 >= 1005 && x4 <= 1010) {
      ans = min(ans, ansa);
    } else {
      ll x_tar_min = 1005*pw[ofs];
      if(x_tar_min <= x) {
        ++ofs;
        x_tar_min *= 10;
      }
      // cout << "x_tar_min=" << x_tar_min << endl;
      ll times = (x_tar_min-x+c-1)/c;
      ll x_res = x+times*c;
      ll div = pw[ofs];
      // cout << "tag " << x_res/div << endl;
      while(x_res/div > 1010) {
        x_tar_min *= 10;
        div *= 10;
        times = (x_tar_min-x+c-1)/c;
        x_res = x+times*c;
        // cout << x_tar_min << ' ' << x << ' ' << x_res << endl;
      }
      ans = min(ans, ansa+times*b);
      // cout << "ans=" << ans << endl;
    }
    ansa += a;
    x /= 10;
    --num;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  pw[0] = 1;
  for(int i = 1; i <= 18; ++i) pw[i] = pw[i-1]*10;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}