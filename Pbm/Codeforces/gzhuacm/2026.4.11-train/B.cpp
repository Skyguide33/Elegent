//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= 2*n; ++j) {
      if((i+(j+1)/2)%2) cout << '.';
      else cout << '#';
    }
    cout << endl;
    for(int j = 1; j <= 2*n; ++j) {
      if((i+(j+1)/2)%2) cout << '.';
      else cout << '#';
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}