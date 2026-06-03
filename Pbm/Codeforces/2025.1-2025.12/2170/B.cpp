//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a.begin()+1, a.end());
  int k = n-1;
  for(int i = n; i >= 1 && k; --i) {
    if(a[i]-1 <= k) {
      k -= a[i]-1; a[i] = 1;
    } else {
      a[i] -= k; k = 0;
    }
  }
  for(int i = n; i >= 1 && k; --i) {
    if(a[i] <= k) {
      k -= a[i]; a[i] = 0;
    } else {
      a[i] -= k; k = 0;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i]) ++ans;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}