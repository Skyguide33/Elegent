//2025/12/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int len = s.length();
  int ans = 0, cnt = 0;
  for(int i = 0; i < len; ++i) {
    if(s[i] == '1') {
      cnt = k;
    } else {
      if(cnt) --cnt;
      else ++ans;
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