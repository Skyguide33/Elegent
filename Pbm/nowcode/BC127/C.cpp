//2026/1/16
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  if(n == 1 || n == 2 || n == 4) cout << -1 << endl;
  else {
    int a = 0, b = 0;
    if(n%2) a = n, b = 0;
    else a = n-3, b = 3;
    for(int i = 1; i <= a/2; ++i) cout << i << ' ';
    for(int i = a/2+1; i >= 1; --i) cout << i << ' ';
    for(int i = 1; i <= b/2; ++i) cout << i << ' ';
    if(b) for(int i = b/2+1; i >= 1; --i) cout << i << ' ';
    cout << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}