//2025/4/5
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  char ab[26];
  int t; cin >> t;
  while(t--) {
    memset(ab, 0, sizeof(ab));
    int n; cin >> n;
    string b; cin >> b;
    for(auto& x: b) ab[x-'a'] = 1;
    string r = "";
    for(int i = 0; i < 26; i++) {
      if(ab[i]) r = r + char(i+'a');
    }
    int len = r.length();
    string s = "";
    for(auto &x: b) {
      s = s + r[len-r.find(x)-1];
    }
    cout << s << endl;
  }
  return 0;
}