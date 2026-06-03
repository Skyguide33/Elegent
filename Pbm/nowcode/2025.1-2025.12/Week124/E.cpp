//2025/12/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007

ll fast_power(ll b, ll p, ll mod) {
  ll res = 1;
  while(p) {
    if(p&1) res = res*b%mod;
    b = b*b%mod;
    p >>= 1;
  }
  return res;
}

int a[200005], b[200005];

int get_mex(int l, int r) {
  for(int i = l; i <= r; ++i) b[i-l] = a[i];
  sort(b, b+r-l+1);
  for(int i = 0; i < r-l+1; ++i) {
    if(b[i] != i) return i;
  }
  return r-l+1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  // for(int i = 1; i <= n; ++i) a[i] = i-1;
  // int flag = 1;
  // int cnt = 0, maxn = 0;
  // while(flag) {
  //   int tt = 0;
  //   for(int i = 1; i <= n; ++i) {
  //     for(int j = i; j <= n; ++j) tt += get_mex(i, j);
  //   }
  //   if(tt > maxn) {
  //     cout << "maxn=" << tt << endl;
  //     for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  //     cout << endl;
  //     maxn = tt, cnt = 1;
  //   }
  //   else if(tt == maxn) {for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
  //     cout << endl;
  //     ++cnt;
  //   }
  //   flag = next_permutation(a+1, a+n+1);
  // }
  // cout << cnt << endl;
  cout << fast_power(2, n/2, MOD) << endl;
  return 0;
}