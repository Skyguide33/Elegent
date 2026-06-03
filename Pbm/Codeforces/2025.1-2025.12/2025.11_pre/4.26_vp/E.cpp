//2025/4/26
#include <bits/stdc++.h>
using namespace std;

int v[100005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> v[i];
  sort(v+1, v+n+1);
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}