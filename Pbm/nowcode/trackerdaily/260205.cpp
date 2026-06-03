//2026/2/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int ans = 0, dep = 0;
  for(char ch: s) {
    if(ch == '(') {
      ++dep;
      ans = max(ans, dep);
    }
    else if(ch == ')' && dep) --dep;
  }
  cout << ans << endl;
  return 0;
}