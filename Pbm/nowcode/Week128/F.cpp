//2026/1/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n = s.length();
  vector<int> tag(n, 0);
  bool flag = 0;
  int block = 0;
  for(int i = n-1; i >= 0; --i) {
    if(s[i] == '0') {
      ++block;
      if(!flag) flag = 1;
    }
    else if(s[i] == '2') flag = 0;
    else if(flag) tag[i] = block;
  }
  int l = 0, r = n-1;
  // for(int i = 0; i < n; ++i) cout << tag[i] << ' ';
  // cout << endl;
  while(l < r) {
    while(l < r && (s[l] != '1' || !tag[l])) ++l;
    while(l < r && s[r] != '1') --r;
    if(l < r && tag[l] == tag[r]) break;
    if(l < r) s[l] = 'e', s[r] = '2';
  }
  for(int i = 0; i < n; ++i) {
    if(s[i] != 'e') cout << s[i];
  }
  cout << endl;
  return 0;
}