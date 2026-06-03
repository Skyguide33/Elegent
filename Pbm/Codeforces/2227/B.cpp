//2026/4/30
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if(n&1) {
    cout << "NO" << endl;
    return;
  }
  int cnt = 0;
  for(int i = 0; s[i]; ++i) {
    if(s[i] == '(') ++cnt;
  }
  if(cnt*2 == n) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}