//2025/8/9
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  string s; cin >> s;
  for(int i = 0; i < s.length(); ++i) {
    if(s[i] == '(' || s[i] ==')') s[i] = '0';
    else s[i] = '1';
  }
  int cnt0 = 0, cnt1 = 0, num2 = 0;
  bool flag = 1;
  for(int i = 0; i < s.length(); ++i) {
    if(s[i] == '0') {
      ++cnt0; cnt1 = 0;
    } else {
      ++cnt1; cnt0 = 0;
    }
    if(cnt0 == 2 || cnt1 == 2) ++num2;
    else if(cnt0 == 3 || cnt1 == 3) flag = 0;
    if(num2 == 3) flag = 0;
  }
  if(flag) cout << "Yes\n";
  else cout << "No\n";
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}