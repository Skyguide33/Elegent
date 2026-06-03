//2025/8/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline bool is_ps(ll x) {
  ll sqrtx = sqrt(x);
  if(sqrtx*sqrtx == x) return 1;
  else return 0;
}

int b[2000005], req[10005], ans[1000005], tail;

void solve() {
  int t, maxq; cin >> t;
  for(int i = 1; i <= t; ++i) {
    cin >> req[i];
    maxq = max(maxq, req[i]);
  }
  b[1] = b[2] = b[4] = 1;
  ans[++tail] = 2;
  for(int i = 3; i <= maxq; ++i) {
    if(!b[i]) {
      ans[++tail] = i;
      b[i] = 1;
      if(tail >= maxq/2) break;
    }
  }
  for(int i = 1; i <= t; ++i) {
    for(int j = 1; j <= req[i]/2; ++j) {
      cout << ans[j] << ' ';
    }
    cout << endl;
  }
  // }
  // int n; cin >> n;
  // for(int n = 4; n <= m; n += 2) {
  //   cout << "n=" << n << ": "; 
  //   vector<ll> a;
  //   a.push_back(2);
  //   bool end = 0;
  //   for(int i = 3; i <= n && !end; ++i) {
  //     bool flag = 1;
  //     for(int j = 0; j < a.size() && flag; ++j) {
  //       for(int k = j; k < a.size() && flag; ++k) {
  //         if(is_ps(i*a[j]*a[k])) flag = 0;
  //       }
  //     }
  //     if(flag) {
  //       a.push_back(i);
  //       if(a.size() == n/2) {
  //         for(int i = 0; i < n/2; ++i) cout << a[i] << ' ';
  //         cout << endl;
  //         flag = 0; end = 1;
  //       }
  //     }
  //   }
  // }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  solve();
  return 0;
}