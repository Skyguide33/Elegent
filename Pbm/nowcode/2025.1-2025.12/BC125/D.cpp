//2025/12/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll pw[18];

void solve() {
  ll x; cin >> x;
  if(x == 0) {
    cout << 1 << endl;
    return;
  }
  ll t = x, cnt = 0;
  ll ans = 0;
  while(t) {
    t /= 10;
    ++cnt;
  }
  for(int i = 1; i < 18; ++i) pw[i] = pw[i-1]*10+1;
  ll f1 = pw[cnt];
  if(x <= f1) {
    ll tt = (f1-x)/9;
    ans = tt+1;
    x += tt*9;
    ans += f1-x;
  } else if((f1*9-x)%9 == 0) ans = (f1*9-x)/9;
  else {
    f1 = pw[cnt+1];
    ll tt = (f1-x)/9;
    ans = tt+1;
    x = (x+tt*9);
    ans += f1-x;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}