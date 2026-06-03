//2025/9/6
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[32], b[32];

void solve() {
  int n; cin >> n;
  for(int i = 0; i < 32; ++i) {
    if(n&(1<<i)) a[i] = 1;
    else a[i] = 0;
  }
  int cnt = 0;
  
  for(int i = 31; i >= 0; --i) {
    if(a[i] == 0) {
      if(a[i+1] == 1) b[i] = 1;
      else b[i] = -1;
    } else {
      if(a[i+1] == 0) {
        b[i] = -1;
      } else if(a[i+1] == 1) {
        b[i] = 1;
      }
    }
  }
  if(a[0] == 0) {
    b[0] = 0;
    if(a[1] == 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  for(int i = 0; i < 32; ++i) {
    cout << b[i] << ' ';
    if((i+1)%8 == 0) cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  
  while(T--) solve();
  return 0;
}