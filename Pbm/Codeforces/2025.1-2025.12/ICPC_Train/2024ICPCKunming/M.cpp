//2025/7/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n, m; cin >> n >> m;
  cout << "Yes" << endl;
  if(m % 2) {
    for(int i = 1; i <= n; ++i) {
      if(i % 2) {
        for(int j = 1; j <= m; ++j) cout << (i-1)*m+j << ' ';
      } else {
        for(int j = 2; j <= m; ++j)  cout << (i-1)*m+j << ' ';
        cout << (i-1)*m+1 << ' ';
      }
      cout << endl;
    }
  } else {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) cout << (i-1)*m+j << ' ';
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