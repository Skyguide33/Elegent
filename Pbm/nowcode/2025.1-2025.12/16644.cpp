//2025/7/21
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int p1, p2, p3; cin >> p1 >> p2 >> p3;
  string s; cin >> s;
  int len = s.length();
  for(int i = 0; i < len; ++i) {
    cout << s[i];
    if(s[i+1] != '-') continue;
    else {
      char l = s[i], r = s[i+2];
      if(isdigit(l) == isdigit(r) && l < r) {
        if(p1 == 3) {
          for(int i = 1; i <= p2*(r-l-1); ++i) cout << '*';
        } else {
          if(isdigit(l)) {
            if(p3 == 1) {
              for(char c = l+1; c < r; ++c)
                for(int i = 1; i <= p2; ++i) cout << c;
            } else {
              for(char c = r-1; c > l; --c)
                for(int i = 1; i <= p2; ++i) cout << c;
            }
          } else {
            if(p3 == 1) {
              for(char c = l+1; c < r; ++c) 
                for(int i = 1; i <= p2; ++i) cout << char(c-(p1-1)*32);
            } else {
              for(char c = r-1; c > l; --c) 
                for(int i = 1; i <= p2; ++i) cout << char(c-(p1-1)*32);
            }
          }
        }
      } else cout << '-';
    }
    i += 1;
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T = 1; //cin >> T;
  while(T--) solve();
  return 0;
}