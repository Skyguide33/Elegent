//2026/5/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  if(n != m || n < 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl << 2 << endl;
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        cout << (i+j-1)%n+1 << ' ';
      }
      cout << endl;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}