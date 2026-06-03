//2025/8/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int p[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void solve() {
  int la, ra, lb, rb; cin >> la >> ra >> lb >> rb;
  int maxans = 0, minn, maxn;
  for(int i = 0; i < 10; ++i) {
    minn = la/p[i]%10 + lb/p[i]%10;
    maxn = ra/p[i]%10 + rb/p[i]%10;
    if(maxn < 10) maxans = max(maxans, maxn);
    else if(maxn == minn) maxans = max(maxans, maxn%10);
    else if()
  }
  if(la == ra) cout << la%10;
  else if(ra < 10) cout << ra;
  else if()
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}