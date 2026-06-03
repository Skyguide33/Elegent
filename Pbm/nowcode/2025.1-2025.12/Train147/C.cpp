//2025/12/19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int fp(int b, ll p, int m) {
  int res = 1;
  while(p) {
    if(p&1) res = 1ll*res*b%m;
    b = 1ll*b*b%m;
    p >>= 1;
  }
  return res;
}

ll an[1000005], bn[1000005];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll a, b, m; cin >> a >> b >> m;
  for(int i = 0; i < m; ++i) {
    // cout << "i=" << i << ", a=" << fp(i, a, m) << ", b=" << fp(i, b, m) << endl;
    ++an[fp(i, a, m)];
    ++bn[fp(i, b, m)];
  }
  ll ans = 0;
  for(int i = 0; i < m; ++i) {
    ans += an[i]*bn[i];
  }
  cout << ans << endl;
  return 0;
}