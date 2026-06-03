//2025/12/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if(s.find("2026") != -1 || s.find("2025") == -1) cout << 0 << endl;
  else  cout << 1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}