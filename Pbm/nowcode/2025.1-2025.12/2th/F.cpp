//2025/9/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, t0; cin >> n >> t0;
  vector<char> a(3*n+2);
  vector<int> b(3*n+2), c(3*n+2);
  for(int i = n+1; i <= 2*n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) {
    a[i] = a[i+n];
    a[i+2*n] = a[i+n];
  }
  cout << "a: ";
  for(int i = 1; i <= 3*n; ++i) cout << a[i] << ' ';
  cout << endl;
  int l = n+1, r = n+2;
  while(l >= 1 && a[l] != '1') --l;
  if(l == 0) {
    cout << n << endl;
    return;
  }
  while(r <= 3*n && a[r] != '1') ++r;
  cout << "l=" << l << ", r=" << r << endl;
  while(r <= 3*n) {
    b[l] = -1, b[r] = -1;
    c[l] = -1, c[r] = -1;
    for(int i = l+1; i < r; ++i) {
      if(i-l <= t0) ++b[i];
      if(r-i <= t0) ++c[i];
    }
    l = r++;
    while(r <= 3*n && a[r] != '1') ++r;
  }
  cout << "b: ";
  int maxlen = 0, cnt2 = 0, res = 0;
  for(int i = 1; i <= 3*n+1; ++i) {
    cout << b[i] << ' ';
    if(b[i] == 1) ++cnt2;
    else {
      maxlen = max(maxlen, cnt2);
      cnt2 = 0;
    }
  }
  for(int i = n+1; i <= 2*n; ++i) {
    if(b[i] == 0) ++res;
  }
  cout << endl;
  cout << format("res={0}, maxlen={1}\n", res, maxlen);
  cout << res+maxlen-1 << endl;
} 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}