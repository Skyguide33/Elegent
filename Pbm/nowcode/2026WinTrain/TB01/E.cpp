//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

void solve() {
  int n, k; cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];
  int ans = -1e9;
  for(int i = 0; i < n-1; ++i) ans = max(ans, a[i]+a[i+1]);
  cout << max({ans, a[0]+k, a[n-1]+k}) << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}