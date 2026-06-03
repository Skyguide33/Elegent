//2025/11/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 998244353

// 带模快速幂
ll fast_power(ll b, ll p, ll mod) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%mod;
    b = (b*b)%mod;
    p >>= 1; 
  }
  return res;
}

// 分解质因数 试除法
ll p[20], c[40]; // 从小到大记录n的质因数和个数(n < 1e16)
int factor(ll n) {
  int cnt = 0, t = sqrt(n);
  for(int i = 2; i <= t; ++i) {
    if(n%i == 0) {
      p[++cnt] = i, c[cnt] = 0;
      while(n%i == 0) n /= i, ++c[cnt];
    }
  }
  if(n > 1) p[++cnt] = n, c[cnt] = 1;
  return cnt; // 返回不同质因数的个数, 遍历下标从1开始
}

void solve() {
  int x, y, n; cin >> x >> y >> n;
  int t = y/x;
  int cnt = factor(t);
  ll res = 1;
  for(int i = 1; i <= cnt; ++i) {
    res = res*((fast_power(c[i]+1, n, MOD)-2*fast_power(c[i], n, MOD)+fast_power(c[i]-1, n, MOD))%MOD+MOD)%MOD;
  }
  cout << res << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}