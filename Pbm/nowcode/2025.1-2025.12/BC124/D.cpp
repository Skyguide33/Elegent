//2025/11/28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int ff[100], cnt;

void solve() {
  int a, b, l, r; cin >> a >> b >> l >> r;
  b -= a;l -= a; r -= a;
  l -= b; r -= b;
  int tt = sqrt(b), cnt = 0;
  for(int i = 1; i <= tt; ++i) {
    if(b%i == 0) ff[++cnt] = i;
  }
  int ans = 0;
  for(int i = 1; i <= cnt; ++i) {
    if(l <= b/ff[i] && b/ff[i] <= r) ++ans;
    if(l <= ff[i] && ff[i] <= r) ++ans;
  }
  if(tt*tt == b && l <= tt && tt <= r) --ans;
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}