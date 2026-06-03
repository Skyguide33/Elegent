//2025/12/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[10005], b[10005], c[10005];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i], a[i+n] = a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i], b[i+n] = b[i];
  for(int i = 1; i <= n; ++i) cin >> c[i], c[i+n] = c[i];
  int cnta = 0;
  for(int i = 1; i <= n; ++i) {
    bool flag = 1;
    for(int j = 1; j <= n; ++j) {
      if(a[i+j-1] >= b[j]) {
        flag = 0;
        break;
      }
    }
    cnta += flag;
  }
  int cntb = 0;
  for(int i = 1; i <= n; ++i) {
    bool flag = 1;
    for(int j = 1; j <= n; ++j) {
      if(b[i+j-1] >= c[j]) {
        flag = 0;
        break;
      }
    }
    cntb += flag;
  }
  cout << 1ll*n*cnta*cntb << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}