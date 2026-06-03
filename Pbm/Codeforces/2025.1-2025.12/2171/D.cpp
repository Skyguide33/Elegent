//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int p[200005], pre[200005], suf[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> p[i];
  pre[0] = 1e9;
  for(int i = 1; i <= n; ++i) {
    pre[i] = min(pre[i-1], p[i]);
  }
  suf[n+1] = 0;
  for(int i = n; i >= 1; --i) {
    suf[i] = max(suf[i+1], p[i]);
  }
  for(int i = 2; i <= n; ++i) {
    if(pre[i-1] > suf[i]) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}