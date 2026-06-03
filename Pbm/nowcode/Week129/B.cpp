//2026/2/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int len = s.length(), l = 0, r = len-1;
  int flag = 0;
  while(l < r) {
    if(s[l] < s[r]) {
      flag = -1;
      break;
    } else if(s[l] > s[r]) {
      flag = 1;
      break;
    }
    ++l; --r;
  }
  if(flag == 1) cout << "left" << endl;
  else if(flag == -1) cout << "right" << endl;
  else cout << "equal" << endl;
  return 0;
}