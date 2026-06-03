//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005], c[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    b[tt] = i;
  }
  for(int i = 1; i <= n; ++i) cin >> c[i];
  bool flag = 1;
  int prep = 0;
  for(int i = 1; i <= n; ++i) {
    if(!c[i]) continue;
    if(b[a[i]] < prep) {
      flag = 0;
      break;
    }
    prep = b[a[i]];
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}