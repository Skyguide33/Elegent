//2025/12/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[100005], b[100005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  ll maxk = 0, mink = 0, t[4];
  for(int i = 1; i <= n; ++i) {
    t[0] = maxk-a[i];
    t[1] = mink-a[i];
    t[2] = b[i]-maxk;
    t[3] = b[i]-mink;
    maxk = LONG_LONG_MIN>>1; mink = LONG_LONG_MAX>>1;
    for(int j = 0; j < 4; ++j) {
      maxk = max(maxk, t[j]);
      mink = min(mink, t[j]);
    }
    // cout << maxk << ' ' << mink << endl;
  }
  cout << maxk << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}