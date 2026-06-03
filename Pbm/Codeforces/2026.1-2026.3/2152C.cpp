//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[250005], num[2][250005], ctn[250005];

void solve() {
  int n, q; cin >> n >> q;
  for(int i = 1; i <= n; ++i) {
    num[0][i] = num[0][i-1];
    num[1][i] = num[1][i-1];
    ctn[i] = ctn[i-1];
    cin >> a[i];
    ++num[a[i]][i];
    if(a[i] == a[i-1]) ++ctn[i];
  }
  while(q--) {
    int l, r; cin >> l >> r;
    if((r-l+1)%3 != 0 || (num[0][r]-num[0][l-1])%3 != 0) {
      cout << -1 << endl;
      continue;
    }
    int ans = (r-l+1)/3;
    int ctn_num = ctn[r]-ctn[l-1];
    if(l > 1 && a[l] == a[l-1]) --ctn_num;
    if(!ctn_num) ++ans;
    cout << ans << endl;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  a[0] = -1;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}