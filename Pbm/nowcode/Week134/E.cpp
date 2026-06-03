//2026/3/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char a[500005];

void solve() {
  int n; cin >> n;
  bool flag0 = 0, flag1 = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(a[i] == '0') flag0 = 1;
    else flag1 = 1;
  }
  if(flag1) cout << n-flag0 << endl;
  else cout << 0 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}