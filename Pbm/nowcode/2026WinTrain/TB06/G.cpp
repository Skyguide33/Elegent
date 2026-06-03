//2026/2/13
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll x[200005], y[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m, l; cin >> n >> m >> l;
  for(int i = 1; i <= n; ++i) cin >> x[i], x[i] += x[i-1];
  for(int i = 1; i <= m; ++i) cin >> y[i], y[i] += y[i-1];
  int idx = 0;
  bool flag = 1;
  for(int i = 0; i <= m; ++i) {
    ll bk = y[i], ft = bk+l;
    while(idx < n && x[idx+1] <= bk) ++idx;
    if(idx == n) break;
    else if(ft > x[idx+1]) {
      flag = 0;
      break;
    }
  }
  if(flag) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}