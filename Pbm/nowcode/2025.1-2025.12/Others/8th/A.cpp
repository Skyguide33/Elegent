//2025/8/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string n; cin >> n;
  if(n == "0") cout << 10;
  else if(n[0] == '-') {
    bool flag = 0;
    for(int i = 0; i < n.length(); ++i) {
      if(!flag && n[i] > '1') {
        cout << 1; flag = 1; --i;
      } else cout << n[i];
    }
    if(!flag) cout << 1;
  } else {
    bool flag = 0;
    for(int i = 0; i < n.length(); ++i) {
      if(!flag && n[i] == '0') {
        cout << 1; flag = 1; --i;
      } else cout << n[i];
    }
    if(!flag) cout << 1;
  } 
  cout << '\n';
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}