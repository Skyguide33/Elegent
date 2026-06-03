//2026/4/29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0;
  while(n--) {
    string s; cin >> s;
    if(s.length() == 5 && s[2] == s[4]) {
      sort(s.begin(), s.begin()+4);
      bool flag = 1;
      for(int i = 0; i < 3; ++i) {
        if(s[i] == s[i+1]) {
          flag = 0;
          break;
        }
      }
      if(flag) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}