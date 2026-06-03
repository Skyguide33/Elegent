//2026/4/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int inv(int b, int m) {
  int res = 1, p = m-2;
  while(p) {
    if(p&1) res = 1ll*res*b%m; 
    b = 1ll*b*b%m;
    p >>= 1;
  }
  return res;
}

void solve() {
  int m, a, b, q; cin >> m >> a >> b >> q;
  string s; cin >> s;
  int n = 0;
  int len = s.length();
  for(int i = 0; i < len; ++i) {
    n = n*2%m;
    if(s[i] == '1') n = (n+1)%m;
  }
  int qn = 1, qb = q;
  for(int i = len-1; i >= 0; --i) {
    if(s[i]) qn = 1ll*qn*qb%m;
    qb = 1ll*qb*qb%m;
  }
  int s = 1ll*n*(n+1)/2%m;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}