//2025/5/24
#include <bits/stdc++.h>
using namespace std;

int a[128];

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    int sg = 0;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < s.length(); ++i) {
      ++a[s[i]]; 
      if(a[s[i]] % 2) ++sg;
      else --sg;
    }
    if(sg <= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}