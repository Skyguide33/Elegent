//2025/11/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define lowbit(x) (x & (-x))
#define MOD 998244353
#define N 1000005

ll a[N], t[N], f[N], n;

void update(int pos) {
  while(pos <= n) {
    ++t[pos];
    pos += lowbit(pos);
  }
}

int query(int pos) {
  int res = 0;
  while(pos) {
    res += t[pos];
    pos -= lowbit(pos);
  }
  return res;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  f[0] = 1;
  for(int i = 1; i < n; ++i) f[i] = f[i-1]*i%MOD;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  ll res = 1;
  for(int i = 1; i <= n; ++i) {
    int cnt = a[i]-1-query(a[i]-1);
    res = (res+cnt*f[n-i])%MOD;
    update(a[i]);
  }
  cout << res << endl;
  return 0;
}