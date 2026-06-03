//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], b[a[i]] = i;
  int swp = 0, swp1 = 0, ok = 0, b1 = 0;
  for(int i = 1; i <= n; ++i) {
    if(b[i] == i) ++ok;
    else if(b[i] == i+1 && b[i+1] == i) ++swp1;
    else if(b[b[i]] == i) ++swp;
    if(b[i] == i-1 || b[i] == i+1) ++b1;
  }
  // cout << ok << ' ' << swp << ' ' << swp1 << ' ' << b1 << endl;
  if(ok == n-2 && swp1) cout << 0 << endl;
  else if(ok == n) cout << 1 << endl;
  else if(swp1) cout << swp/2+swp1/2-1+(n-ok-1-swp-swp1) << endl;
  else if(b1) cout << swp/2+(n-ok-2-swp) << endl;
  else cout << swp/2+n-ok-swp+1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}