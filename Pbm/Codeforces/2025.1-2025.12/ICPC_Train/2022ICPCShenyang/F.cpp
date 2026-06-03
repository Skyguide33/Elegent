//2025/11/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1000005];

void solve() {
  int n, m; cin >> n >> m;
  bool inv = 0;
  int len = 0;
  if(m%4 == 0 || m%4 == 3) len = m;
  else if(n%4 == 0 || n%4 == 3) len = n, inv = 1;
  else {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;
  ll num = 1ll*len*(len+1)/4-len;
  a[1] = 0;
  int cnt = 1;
  for(int i = 2; i <= len; ++i) {
    if(num >= cnt) {
      a[i] = a[i-1];
      num -= cnt;
    } else {
      a[i] = a[i-1]^1;
      cnt = 0;
    }
    ++cnt;
  }
  if(inv) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) cout << a[i] << ' ';
      cout << endl;
    }
  } else {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) cout << a[j] << ' ';
      cout << endl;
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}