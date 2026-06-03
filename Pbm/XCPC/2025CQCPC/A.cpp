//2026/5/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[200005], b[200005];

void solve() {
  int n; cin >> n;
  bool flag = 1;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(i > 0 && a[i] != a[i-1]) flag = 0;
  }
  if(flag == 1) {
    cout << 0 << endl;
    return;
  }
  int ans = 0;
  while(1) {
    ++ans;
    bool flag = 1;
    for(int i = 0; i < n; ++i) b[i] = a[i];
    for(int i = 0; i < n; ++i) {
      b[i] = a[i]|a[(i+ans)%n];
    }
    for(int i = 0; i < n; ++i) {
      a[i] = b[i];
      if(i > 0 && a[i] != a[i-1]) flag = 0;
    }
    if(flag) break;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}