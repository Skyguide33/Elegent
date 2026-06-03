//2025/8/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
  cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
  if(sx1 > sx2) swap(sx1, sx2);
  if(sy1 > sy2) swap(sy1, sy2);
  if(tx1 > tx2) swap(tx1, tx2);
  if(ty1 > ty2) swap(ty1, ty2);
  bool vers = sy2-sy1, vert = ty2-ty1;
  ll ans = 0;
  if(vers != vert) {
    ans = 1;
    if(vers) {
      if(ty1 >= sy2) ty1 -= 1;
      else ty2 += 1;
      if(tx2 <= sx1) tx1 += 1; 
      else tx2 -= 1;
    } else {
      if(tx1 <= sx1) tx2 += 1;
      else tx1 -= 1;
      if(ty1 >= sy1) ty2 -= 1;
      else  ty1 += 1;
    }
  }
  ans += max(abs(sx1-tx1), abs(sy1-ty1))*2;
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}