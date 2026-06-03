//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int idx = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i]%6 == 0) b[++idx] = a[i];
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i]%2 == 0 && a[i]%6) b[++idx] = a[i];
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i]%2 && a[i]%3) b[++idx] = a[i];
  }
  for(int i = 1; i <= n; ++i) {
    if(a[i]%2 && a[i]%3 == 0) b[++idx] = a[i];
  }
  for(int i = 1; i <= n; ++i) cout << b[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}