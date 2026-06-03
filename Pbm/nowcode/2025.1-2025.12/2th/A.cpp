//2025/9/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll MOD = 998244353;

void solve() {
  int n; cin >> n;
  vector<int> a(n+1, 0);
  vector<ll> b(n+1);
  b[0] = 1;
  for(int i = 1; i <= n; ++i) b[i] = b[i-1]*2%MOD;
  int cnt = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] == -1) ++cnt;
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    if(a[i-1] == 0) {
      if(a[i] == 1) {
        ans = (ans+b[cnt])%MOD;
        ++i;
      } else if(a[i] == -1) {
        ans = (ans+b[cnt-1])%MOD;
      } 
    } else if(a[i-1] == -1) {
      if(a[i] == 1) {
        ans = (ans+b[cnt-1])%MOD;
        ++i;
      } else if(a[i] == -1) {
        ans = (ans+b[cnt-2])%MOD;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}