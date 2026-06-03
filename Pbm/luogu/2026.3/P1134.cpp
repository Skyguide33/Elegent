//2026/3/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  ll ans = 1;
  for(int i = 1; i <= n; ++i) {
    ans *= i;
    while(ans%10 == 0) ans /= 10;
    ans %= 100000000000;
  }
  cout << ans%10 << endl;
  return 0;
}