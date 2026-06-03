//2025/11/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  int len = s.length();
  x = abs(x); y = abs(y);
  int lck = 0;
  for(int i = 0; i < len; ++i) {
    if(s[i] == '4') ++lck;
  }
  if(x > len || y > len-(max(0, lck-(len-x)))) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}