//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, k, tt; cin >> n >> k;
  vector<vector<int>> a(n+1, vector<int>(4, 0));
  vector<int> b(n+1);
  for(int i = 1; i <= n; ++i) {
    cin >> tt;
    ++a[tt][1];
    if(tt%2 == 0) ++a[tt/2][2];
    if(tt%3 == 0) ++a[tt/3][3];
    if(tt > 3) {
      ++b[1];
      --b[tt/4+1];
    }
  }
  for(int i = 1; i <= n; ++i) b[i] += b[i-1];
  int ans = 1;
  for(int i = 2; i <= n; ++i) {
    if(a[i][1]+a[i][2]+a[i][3]+b[i] >= n-k) ans = i;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}