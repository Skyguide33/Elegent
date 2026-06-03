//2026/3/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0;
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(2*i+3*j <= n && i <= 2*j+1) ans = max(ans, i+j);
    }
  }
  cout << setprecision(9) << fixed << ans << endl;
  return 0;
}