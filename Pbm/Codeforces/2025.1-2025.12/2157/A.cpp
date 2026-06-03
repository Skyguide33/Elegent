//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1), b(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i], ++b[a[i]];
  int ans = 0;
  for(int i = 0; i <= n; ++i) {
    if(b[i] != 0) {
      if(b[i] < i) ans += b[i];
      else if(b[i] > i) ans += b[i]-i;
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