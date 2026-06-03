//2026/2/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], p[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> p[i];
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int j = 1;
  bool flag = 1;
  for(int i = 1; i <= n; ++i) {
    while(j <= n && p[j] != a[i]) ++j;
    if(j > n) {
      flag = 0;
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