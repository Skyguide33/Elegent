//2025/12/11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = s+s;
  int ans = 0, cnt = 0;
  for(int i = 0; i < 2*n; ++i) {
    if(s[i] == '0') ++cnt;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}