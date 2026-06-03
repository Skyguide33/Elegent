//2026/2/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, m, d; cin >> n >> m >> d;
  int h = d/m+1;
  cout << (n+h-1)/h << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}