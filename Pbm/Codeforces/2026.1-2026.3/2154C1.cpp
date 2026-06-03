//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1), b(n+1);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  set<int> mpf;
  bool flag = 0;
  int even = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i]%2 == 0) ++even;
    int tt = a[i];
    int tr = sqrt(tt);
    for(int i = 2; i <= tr; ++i) {
      if(tt%i == 0) {
        if(mpf.contains(i)) {
          flag = 1;
          break;
        } else mpf.insert(i);
        while(tt%i == 0) tt /= i;
      }
    }
    if(tt != 1) {
      if(mpf.contains(tt)) {
        flag = 1;
        break;
      } else mpf.insert(tt);
    }
  }
  if(flag) {
    cout << 0 << endl;
    return;
  } else if(even == 1) {
    cout << 1 << endl;
    return;
  } 
  for(int i = 1; i <= n; ++i) {
    int tt = a[i]+1;
    int tr = sqrt(tt);
    for(int i = 2; i <= tr; ++i) {
      if(tt%i == 0) {
        if(mpf.contains(i)) {
          flag = 1;
          break;
        }
        while(tt%i == 0) tt /= i;
      }
    }
    if(tt != 1) {
      if(mpf.contains(tt)) {
        flag = 1;
        break;
      } 
    }
  }
  if(flag) cout << 1 << endl;
  else cout << 2 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}