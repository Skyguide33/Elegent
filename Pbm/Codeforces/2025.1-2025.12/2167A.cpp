//2025/11/20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[4];

void solve() {
  for(int i = 0; i < 4; ++i) cin >> a[i];
  sort(a, a+4);
  if(a[0] != a[3]) cout << "No" << endl;
  else cout << "Yes" << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}