//2026/2/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll fast_power(ll b, ll p, ll m) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%m;
    b = b*b%m;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a, b, p; cin >> a >> b >> p;
  cout << format("{}^{} mod {}={}", a, b, p, fast_power(a, b, p)) << endl;
  return 0;
}