//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, x = 0, bit, idx; cin >> n;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i) cin >> a[i], x ^= a[i];
  for(int i = 0; i < n; ++i) cin >> b[i], x ^= b[i];
  if(!x) {
    cout << "Tie" << endl;
    return;
  }
  // 找到最高位
  for(int i = 0; i < 20; ++i) {
    if(x&(1<<i)) bit = i;
  }
  // 谁能最后决定最高位谁就可以赢
  // 找到最后一个含有最高位的位置下标
  for(int i = 0; i < n; ++i) {
    if((a[i]^b[i])&(1<<bit)) idx = i;
  }
  cout << (idx&1? "Mai": "Ajisai") << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}