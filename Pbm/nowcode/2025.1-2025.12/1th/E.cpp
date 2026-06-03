//2025/8/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  ll a, b; cin >> a >> b;
  ll h = abs(a*a-b*b);
  if(h == 3) cout << 1 << endl;
  else if(h == 5) cout << 2 << endl;
  else cout << h-4-(h-7)/4 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}