//2026/3/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] ^= a[i-1];
  }
  int tag = a[n];
  ll ans = 0, zcnt = 0;
  if(a[n-1] == 0) ++zcnt;
  for(int i = n-2; i >= 1; --i) {
    if(a[i] == tag) ans += zcnt;
    if(a[i] == 0) ++zcnt;
  }
  cout << ans << endl;
  return 0;
}