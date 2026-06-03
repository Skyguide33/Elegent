//2026/2/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[5005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    int cnt = 0;
    for(int j = 1; j <= n; ++j) {
      if(i != j) {
        if(a[j] <= a[i]) ++cnt;
      }
    }
    if(4*(n-1) <= cnt*5) ans += a[i];
  }
  cout << ans << endl;
  return 0;
}