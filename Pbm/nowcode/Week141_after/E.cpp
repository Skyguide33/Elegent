//2026/4/26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], q[200005][2];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n, m; cin >> n >> m;
  ll min_n = 2*m, max_n = 1ll*(1+m)*m/2+1;
  if(n < min_n || n > max_n) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int r = n-1, c = 0;
    a[0] = 1;
    for(int i = m; i >= 1; --i) {
      if((c+1)*i <= r) ++c;
      a[i] = c;
      r -= c;
    }
    // for(int i = 0; i <= m; ++i) {
    //   cout << a[i] << ' ';
    // }
    // cout << endl;
    int idx = 1;
    for(int i = 1; i <= m; ++i) {
      for(int j = 1; j <= a[i]; ++j) {
        if(i == 1) {
          cout << 1 << ' ' << ++idx << endl;
        } else if(a[i-1] == a[i]) {
          ++idx;
          cout << idx-a[i]+(j != a[i]) << ' ' << idx << endl;
        } else {
          ++idx;
          cout << idx-a[i] << ' ' << idx << endl;
        }
      }
    }
  }
  return 0;
}