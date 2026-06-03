//2025/6/6
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int m, s, t, fla = 0, run = 0; cin >> m >> s >> t;
  for(int i = 1; i <= t; ++i) {
    if(m >= 10) {
      fla += 60; m -= 10;
    } else {
      run = max(run, fla); m += 4;
    }
    run += 17;
    if(max(fla, run) >= s) {
      cout << "Yes\n" << i << endl;
      return 0;
    }
  }
  cout << "No\n" << max(fla, run) << endl;
  return 0;
}