//2025/8/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll r = 1500, n, t; cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> t; r += t;
    if(r >= 4000) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}