//2025/12/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[400005];

void solve() {
  int n, l, r; cin >> n >> l >> r;
  for(int i = 0; i <= n; ++i) {
    if(i == l-1 || i == r) a[i] = 1000000;
    else a[i] = i;
  }
  for(int i = n; i >= 1; --i) a[i] ^= a[i-1];
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}