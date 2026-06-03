//2025/12/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[100005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int ans = a[n]-a[1];
  for(int i = 2; i <= n; ++i) {
    ans = min(ans, 8-a[i]+a[i-1]);
  }
  cout << ans << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}