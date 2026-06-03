//2026/3/27
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int c[26];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n; cin >> n;
  int ans = 0, st = 0;
  for(int i = 1; i <= n; ++i) {
    char ch; cin >> ch;
    if(st) --st;
    else {
      ++ans;
      ++c[ch-'a'];
    }
    if(c['g'-'a'] && c['z'-'a'] && c['h'-'a'] && c['u'-'a']) {
      st += c['g'-'a']+c['z'-'a']+c['h'-'a']+c['u'-'a'];
      c['g'-'a']  = 0; c['z'-'a'] = 0; c['h'-'a'] = 0; c['u'-'a'] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}