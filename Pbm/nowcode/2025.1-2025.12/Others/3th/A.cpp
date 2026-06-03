//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[1415][1415];  

void solve() {
  int n, f, skip; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> f;
    skip = 1;
    for(int j = 1; j <= i; ++j) {
      if(j+skip == f) ++skip;
      a[j][i] = a[i][j] = j+skip;
    }
    if(f == 1) a[i][i] = 0;
    else {
      a[i-1][i] = a[i][i-1] = 0; a[i][i] = 1;
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) cout << a[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}