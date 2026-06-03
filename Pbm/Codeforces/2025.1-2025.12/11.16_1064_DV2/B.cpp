//2025/11/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll a, b, n; cin >> a >> b >> n;
  if(b*n > a && a != b) cout << 2 << endl;
  else cout << 1 << endl; 
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}