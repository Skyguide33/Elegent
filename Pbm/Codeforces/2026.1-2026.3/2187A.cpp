//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
  sort(b+1, b+n+1);
  bool flag = 1;
  for(int i = 1; i <= n; ++i) {
    if(a[i] != b[i]) {
      flag = 0;
      break;
    }
  }
  if(flag) {
    cout << -1 << endl;
    return;
  }
  int k = INT_MAX>>1;
  for(int i = 1; i <= n; ++i) {
    if(a[i] != b[i]) k = min(k, max(a[i]-b[1], b[n]-a[i]));
  }
  cout << k << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}