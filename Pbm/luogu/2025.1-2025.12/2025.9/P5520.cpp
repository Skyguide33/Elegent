//2025/9/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int tp, n, m, p; cin >> tp >> n >> m >> p;
  int st = n-2*m+2, ed = n-m+1;
  if(st < 0) cout << 0 << endl;
  else {
    int ans = 1;
    for(int i = st; i <= ed; ++i) ans = 1ll*ans*i%p;
    cout << ans << endl;
  }
  return 0;
}