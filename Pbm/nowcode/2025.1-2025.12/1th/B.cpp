//2025/8/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m; cin >> n >> m;
  int minm = (n+1)*n/2;
  if(m < minm) {
    cout << -1 << endl;
    return;
  }
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}