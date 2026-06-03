//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
int a[200005];
 
void solve() {
  int n; cin >> n;
  int even = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i]%2 == 0) ++even;
  }
  int odd = n-even;
  --even;
  if(odd*2 >= even) cout << "YES" << endl;
  else cout << "NO" << endl;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}