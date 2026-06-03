//2026/3/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
int c[33][33];

void solve() {
  int n, k; cin >> n >> k;
  ll ans = 0;
  int tt = n, cnt = -2;
  while(tt) {
    ++cnt;
    tt >>= 1;
  }
  --k;
  if(int(log2(n)) <= k) ++ans;
  while(cnt > -1) {
    for(int cnt0 = max(0, 2*cnt-k); cnt0 <= min(k, cnt); ++cnt0) {
      ans += c[cnt][cnt0];
    }
    --cnt;
  }
  cout << n-ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  for(int i = 0; i < 32; ++i) {
    c[i][0] = c[i][i] = 1;
    for(int j = 1; j < i; ++j) c[i][j] = c[i-1][j]+c[i-1][j-1];
  }
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}