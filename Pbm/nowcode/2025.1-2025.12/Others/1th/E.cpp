//2025/7/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    ll a, b; cin >> a >> b;
    ll x = abs(a*a - b*b);
    if(x == 3) cout << 1 << endl;
    else if(x == 5) cout << 2 << endl;
    else cout << x-4-(x-6)/4 << endl;
  }
  return 0;
}