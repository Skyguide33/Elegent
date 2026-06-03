//2026/2/3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0, cnt = 0;
  int flag = -1;
  for(int i = 0; i < n; ++i) {
    if(s[i] == 'a' && flag != 0) {
        flag = 0;
        ++cnt;
    } else if(s[i] == 'h' && flag != 1) {
        flag = 1;
        ++cnt;
    } else {
      ans = max(ans, cnt);
      cnt = 0;
      if(s[i] == 'a' || s[i] == 'h') ++cnt;
    }
  }
  cout << max(ans, cnt) << endl;
  return 0;
}