//2026/4/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if(a < b && b < c) cout << "STAIR" << endl;
  else if(a < b && b > c) cout << "PEAK" << endl;
  else cout << "NONE" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}