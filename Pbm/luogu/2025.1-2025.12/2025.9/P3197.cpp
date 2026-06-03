//2025/9/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int MOD = 100003;

int fast_power(ll b, ll p) {
  int res = 1;
  while(p) {
    if(p&1) res = (res*b)%MOD;
    b = b*b%MOD;
    p >>= 1;
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n, m; cin >> m >> n;
  cout << 1ll*(fast_power(m, n)-m*fast_power(m-1, n-1)-MOD)%MOD+MOD << endl;
  return 0;
}