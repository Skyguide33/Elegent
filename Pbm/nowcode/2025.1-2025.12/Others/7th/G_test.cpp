//2025/8/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline bool is_ps(ll x) {
  ll sqrtx = sqrt(x);
  if(sqrtx*sqrtx == x) return 1;
  else return 0;
}

void solve_test() {
  int m; cin >> m;
  for(int n = 4; n <= m; n += 2) {
    cout << "n=" << n << ": "; 
    vector<ll> a;
    a.push_back(2);
    bool end = 0;
    for(int i = 3; i <= n && !end; ++i) {
      bool flag = 1;
      for(int j = 0; j < a.size() && flag; ++j) {
        for(int k = j; k < a.size() && flag; ++k) {
          if(is_ps(i*a[j]*a[k])) flag = 0;
        }
      }
      if(flag) {
        a.push_back(i);
        if(a.size() == n/2) {
          for(int i = 0; i < n/2; ++i) cout << a[i] << ' ';
          cout << endl;
          flag = 0; end = 1;
        }
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve_test();
  return 0;
}