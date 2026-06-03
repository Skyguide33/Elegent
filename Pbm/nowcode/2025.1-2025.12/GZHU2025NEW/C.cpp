//2025/12/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  string s; cin >> s;
  int len = s.length();
  int ans = 0;
  for(int i = 0; i < len; ++i) {
    if(s[i] == '1') {
      ++ans; ++i;
    }
  }
  cout << ans << endl;
  return 0;
}