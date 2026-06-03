//2025/12/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  n = unique(a+1, a+n+1)-a-1;
  // cout << n << endl;
  bool flag = 0;
  for(int i = m-1; i <= n; ++i) {
    if(a[i]-a[i-m+2] == m-1 || a[i]-a[i-m+2] == m-2) {
      flag = 1;
      break;
    }
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}