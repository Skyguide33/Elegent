//2025/12/12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  if(n <= 2) cout << -1 << endl;
  else if(n == 4) cout << "2 4 1 3" << endl;
  else if(n%2) {
    for(int i = 2; i <= n; ++i) cout << i << ' ';
    cout << 1 << endl;
  } else {
    for(int i = 2; i <= n-3; ++i) cout << i << ' ';
    cout << 1 << ' ' << n-1 << ' ' << n << ' ' << n-2 << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}