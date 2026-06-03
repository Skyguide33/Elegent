//2025/12/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll a[200005], b[200005], c[200005], ans[200005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int bn = 0, cn = 0;
  for(int i = n; i >= 1; --i) {
    if(a[i]%2) b[++bn] = a[i];
    else c[++cn] = a[i];
  }
  if(!bn) {
    for(int i = 1; i <= n; ++i) cout << 0 << ' ';
    return;
  }
  else if(!cn) {
    for(int i = 1; i <= n; ++i) {
      if(i%2) cout << b[1] << ' ';
      else cout << 0 << ' ';
    }
    cout << endl;
    return;
  }
  ans[1] = b[1];
  int idx = 2;
  for(; idx <= n; ++idx) {
    if(idx-1 > cn) break;
    ans[idx] = ans[idx-1]+c[idx-1];
  }
  int bi = bn-1;
  int tt = idx;
  for(; idx <= n; ++idx) {
    if(bi <= 1) break;
    else {
      if((idx-tt)%2) {
        ans[idx] = ans[tt-1];
        bi -= 2;
      } else {
        ans[idx] = ans[tt-1]-c[cn];
      }
    }
  }
  for(; idx <= n; ++idx) {
    if(idx == n) {
      if(bn%2) ans[idx] = b[1];
      else ans[idx] = 0;
    } else if(idx > cn) {
      if(idx%2) ans[idx] = b[1];
      else ans[idx] = 0;
    } else ans[idx] = b[1];
  }
  for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}