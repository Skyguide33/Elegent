//2025/7/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  char s[5]; cin >> s;
  if(s[0] == s[2] || (s[1] == '-' && s[0] == '0')) cout << "No\n";
  else cout << "Yes\n";
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}

