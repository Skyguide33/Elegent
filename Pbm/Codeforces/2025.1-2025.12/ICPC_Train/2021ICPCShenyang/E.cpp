//2025/11/5
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int cnt = 0, len = s.length();
  int p = 0;
  for(int i = 0; i < len; ++i) {
    if(s[i] == 'e')  p = 1;
    else if(s[i] == 'd' && p == 1) p = 2;
    else if(s[i] == 'g' && p == 2) p = 3;
    else if(s[i] == 'n' && p == 3) p = 4;
    else if(s[i] == 'b' && p == 4) {
      ++cnt; p = 0;
    } else p = 0;
  }
  cout << cnt << endl;
  return 0;
}