//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int a[3]; 
  for(int i = 0; i < 3; ++i) cin >> a[i];
  sort(a, a+3);
  if(a[2]-a[0] > 1) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}