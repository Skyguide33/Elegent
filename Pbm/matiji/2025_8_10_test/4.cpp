//2025/8/10
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n; cin >> n;
  if(n % 2) {
    for(int i = 1; i <= n; ++i) cout << i << ' ';
  } else {
    for(int i = 2; i <= n; i += 2) {
      cout << i << ' ' << i-1 << ' ';
    }
  }
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}