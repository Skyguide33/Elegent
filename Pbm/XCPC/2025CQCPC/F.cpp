//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if(a > b) cout << "Win" << endl;
  else if(c > b) cout << "WIN" << endl;
  else cout << "nowin" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}