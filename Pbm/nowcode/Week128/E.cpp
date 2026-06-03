//2026/1/25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  string s; cin >> s;
  int n = s.length();
  int cnt = 0;
  for(int i = 0; i < n; ++i) 
    if(s[i] == '1') ++cnt;
  if(cnt%2) {
    int cntl = 0;
    for(int i = 0; i < n-1; ++i) {
      if(s[i] == '1') {
        if(++cntl > cnt/2+1) break;
        if(s[i+1] == '2') {
          s[i] = 'r';
          break;
        }
      } 
    }
  }
  int l = 0, r = n-1;
  while(l < r) {
    while(l < r && s[l] != '1') ++l;
    while(l < r && s[r] != '1') --r;
    if(l < r) s[l] = 'e', s[r] = '2';
  }
  for(int i = 0; i < n; ++i) {
    if(s[i] == '1' || s[i] == 'r') cout << '1';
    else if(s[i] != 'e') cout << s[i];
  }
  cout << endl;
  return 0;
}