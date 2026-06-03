//2026/3/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  cout << (1<<n)-1 << ' ';
  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < (1<<i); j += 2) cout << (1<<(n-i))-1+(j<<(n-i)) << ' ';
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}