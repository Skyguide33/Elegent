//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  double x[5], y[5];
  for(int i = 1; i <= 4; ++i) {
    cin >> x[i] >> y[i];
  }
  double avgx = (x[1]+x[3])/2, avgy = (y[1]+y[3])/2;
  for(int i = 1; i <= 4; ++i) {
    x[i] -= avgx; y[i] -= avgy;
    // cout << x[i] << ' ' << y[i] << endl;
  }
  if(x[1] == x[2] || x[2] == x[3]) {
    cout << 1 << endl;
    return;
  }
  
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}