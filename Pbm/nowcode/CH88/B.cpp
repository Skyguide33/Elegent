//2026/5/15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[101][101], m;

bool equal(int src[], int otr[]) {
  for(int i = 1; i <= m; ++i) {
    if(src[i] < otr[i]) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      char tt; cin >> tt;
      a[i][j] = '1'-tt;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    int res = 0;
    for(int j = 1; j <= m; ++j) {
      if(a[i][j]) {
        a[i][j] = 0;
        bool flag = 1;
        for(int k = 1; k <= n; ++k) {
          if(k == i) continue;
          if(equal(a[i], a[k])) {
            flag = 0;
            break;
          }
        }
        a[i][j] = 1;
        res += flag;
      }
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}