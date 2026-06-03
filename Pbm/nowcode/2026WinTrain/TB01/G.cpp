//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int pw[16];

string revnum(int num) {
  string res = to_string(num);
  reverse(res.begin(), res.end());
  return res;
}

int num_wide(int num) {
  return to_string(num).size();
}

void solve() {
  int l, r; cin >> l >> r;
  if(l == r) {
    string ans = revnum(l);
    while(ans.front() == '0') ans.erase(ans.begin());
    cout << ans << endl;
    return;
  }
  if(r%10 == 0) --r;
  if(num_wide(l) != num_wide(r)) {
    l = pw[num_wide(r)-1];
  }
  string ls = to_string(l), rs = to_string(r);
  int len = rs.length(), pos = len;
  for(int i = 0; i < len; ++i) {
    if(ls[i] != rs[i]) {
      pos = i;
      break;
    }
  }
  bool flag = 0;
  for(int i = pos+1; i < len; ++i) {
    if(rs[i] != '9') {
      rs[i] = '9';
      flag = 1;
    }
  }
  if(flag) rs[pos] -= 1;
  for(int i = len-1; i >= 0; --i) cout << rs[i];
  cout << endl;
}

signed main() {
  cin.tie(0) -> sync_with_stdio(0);
  pw[0] = 1;
  for(int i = 1; i <= 15; ++i) pw[i] = pw[i-1]*10;
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}