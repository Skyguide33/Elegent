//2025/6/
#include <bits/stdc++.h>
using namespace std;
#define MOD 5
#define ll long long

int mul(int a, int b, int m) {
  a %= m; b %= m;
  int res = 0;
  while(b) {
    if(b & 1) res = (res+a) % m;
    a = (a<<1) % m;
    b >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int a, b, m; cin >> a >> b >> m;
  int res = mul(a, b, m);
  cout << res << endl;
  return 0;
}