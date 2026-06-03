//2026/3/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  vector<int> a(n+1);
  a[n] = 1;
  if(n&1) a[1] = n^1;
  else a[1] = n;
  for(int i = 2; i < n; ++i) a[i] = i^1;
  for(int i = 1; i <= n; ++i) cout << a[i] << ' ' ;
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}