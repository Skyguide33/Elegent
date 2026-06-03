//2026/2/8
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  int n; cin >> n;
  string s[n];
  for(int i = 0; i < n; ++i) cin >> s[i];
  int type = 0;
  int flag = 0;
  for(int i = 0; i < n; ++i) {
    flag = 1;
    for(int j = 0; j < n; ++j) {
      if(s[i][j] == '*') {
        if(i < n-1 && j < n-1 && s[i][j+1] == '*' && s[i+1][j] == '*') type = 1;
        flag = 0;
        break;
      }
    }
    if(!flag) break;
  }
  for(int i = 0; i < n; ++i) {
    flag = 1;
    for(int j = n-1; j >= 0; --j) {
      if(s[i][j] == '*') {
        if(i < n-1 && j > 0 && s[i][j-1] == '*' && s[i+1][j] == '*') type = 1;
        flag = 0;
        break;
      }
    }
    if(!flag) break;
  }
  for(int i = n-1; i >= 0; --i) {
    flag = 1;
    for(int j = 0; j < n; ++j) {
      if(s[i][j] == '*') {
        if(i > 0 && j < n-1 && s[i][j+1] == '*' && s[i-1][j] == '*') type = 1;
        flag = 0;
        break;
      }
    }
    if(!flag) break;
  }
  for(int i = n-1; i >= 0; --i) {
    flag = 1;
    for(int j = n-1; j >= 0; --j) {
      if(s[i][j] == '*') {
        if(i > 0 && j > 0 && s[i][j-1] == '*' && s[i-1][j] == '*') type = 1;
        flag = 0;
        break;
      }
    }
    if(!flag) break;
  }
  if(type) cout << 'L' << endl;
  else cout << 'T' << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}