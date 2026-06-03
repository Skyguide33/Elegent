//2026/2/23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if(n&1) {
    s = 'b'+s;
    ++n;
  }
  for(int i = 1; i < n; i += 2) {
    if(s[i] == '?' || s[i-1] == '?' || s[i] != s[i-1]) continue;
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}