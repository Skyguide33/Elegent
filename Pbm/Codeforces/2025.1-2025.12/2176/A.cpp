//2025/12/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int ans = 0;
  for(int i = n; i >= 2; --i) {
    for(int j = i-1; j >= 1; --j) {
      if(a[j] > a[i]) {
        ++ans;
        break;
      }
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