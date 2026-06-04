//2026/6/4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  stack<int> st1, st2;
  int now = 1;
  string ans;
  for(int i = 1; i <= n; ++i) {
    int tt; cin >> tt;
    if(st1.empty() || tt < st1.top()) {
      st1.push(tt);
      ans += 'a';
    }
    
  } 
  return 0;
}