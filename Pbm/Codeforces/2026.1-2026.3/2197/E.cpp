//2026/2/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int sqtn= sqrt(n);
  int ans = 0;
  for(int j = 2; j <= n; ++j) {
    if(a[j] >= n) continue;
    for(int k = 1; k <= min(a[j], sqtn); ++k) {
      if(j-k*a[j] >= 1 && a[j-k*a[j]] == k) ++ans;
    }
  }  
  for(int j = 1; j < n; ++j) {
    if(a[j] >= n) continue;
    for(int k = 1; k <= min(a[j]-1, sqtn); ++k) {
      if(j+k*a[j] <= n && a[j+k*a[j]] == k) ++ans;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}