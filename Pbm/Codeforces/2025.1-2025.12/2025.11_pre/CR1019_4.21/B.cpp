//2025/4/21
#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int ans = n;
    cin >> s;
    s.insert(s.begin(), '0');
    for(int i = 1; i <= n; ++i) {
      if(s[i-1] != s[i]) ++ans;
    }
    for(int i = 1; i <= n; ++i) {
      if(s[i-1] != s[i]) {
        if(i == 1) continue;
        else if(i <= n-2) {
          for(int k = i+2; k <= n; ++k) {
            if(s[i-1]==s[k-1] && s[i]==s[k]) {
              // cout << "opt-2" << endl;
              ans -= 2;
              break;
            }
          }
          if(s[n] != s[i]) --ans;
        } else if(i == n-1 && s[i+1] != s[i]) {
          // cout << "opt-1" << endl;
          --ans;
        }
        break;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}