//2025/11/14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
  string s; cin >> s;
  int len = s.length();
  if(len == 1) {
    cout << 1 << endl;
    return;
  }
  bool flag = 1;
  for(int i = 0; i < len; ++i) {
    if(s[i] != '<') {
      flag = 0; break;
    }
  }
  if(flag) {
    cout << len << endl;
    return;
  }
  flag = 1;
  for(int i = 0; i < len; ++i) {
    if(s[i] != '>') {
      flag = 0; break;
    }
  }
  if(flag) {
    cout << len << endl;
    return;
  }
  int lenl = -1, lenr = -1;
  for(int i = 0; i < len; ++i) {
    if(s[i] != '<') {
      lenl = i;
      break;
    }
  }
  for(int i = len-1; i >= 0; --i) {
    if(s[i] != '>') {
      lenr = i;
      break;
    }
  }
  if(lenl == lenr) {
    cout << max(lenl+1, len-lenr) << endl;
  } 
  else if(lenl==lenr+1){
    cout << max(lenl, len-lenr-1) << endl;
  }
  else cout << -1 << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; cin >> T;
  while(T--) solve();
  return 0;
}